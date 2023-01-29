from datetime import datetime
from collections import defaultdict


class OrderedCountNode:
    """
    Keep track of the keys used at a particular count,
    maintaining the order of access using a linked list
    """
    def __init__(
        self,
        key: int,
        count: int,
        used_after_me: Optional["OrderedCountNode"] = None,
        used_before_me: Optional["OrderedCountNode"] = None,
    ):
        self.key = key
        self.count = count
        self.used_after_me = used_after_me
        self.used_before_me = used_before_me
    
    def __str__(self) -> str:
        after_key = self.used_after_me.key if self.used_after_me else None
        before_key = self.used_before_me.key if self.used_before_me else None
        return f'[{self.key} ({self.count}), ({before_key},{after_key})]'

    def __repr__(self) -> str:
        return str(self)


class LFUCache:

    def __init__(self, capacity: int):
        self._capacity = capacity
        self._values = {}
        self._min_count = 0
        self._most_recent_count_nodes = {}
        self._least_recent_count_nodes = {}
        self._nodes_by_key = {}

    def get(self, key: int) -> int:
        value = self._values.get(key, -1)
        if value != -1:
            self._update_counts(key)
        return value
        
    def put(self, key: int, value: int) -> None:
        current_size = len(self._values)
      
        if current_size >= self._capacity and key not in self._values:
            self._evict()

        if len(self._values) < self._capacity or key in self._values:
           self._update_counts(key)
           self._values[key] = value

    def _update_counts(self, key: int) -> None:
        node = self._nodes_by_key.get(key)
        before_count = node.count if node else 0

        if node:
            if node.used_before_me:
                node.used_before_me.used_after_me = node.used_after_me
            else:
                self._least_recent_count_nodes[before_count] = node.used_after_me
            if node.used_after_me:
                node.used_after_me.used_before_me = node.used_before_me
            else:
                self._most_recent_count_nodes[before_count] = node.used_before_me

        new_count = before_count + 1
        new_node = OrderedCountNode(key, new_count)

        prior_node = self._most_recent_count_nodes.get(new_count)
        
        if prior_node:
            prior_node.used_after_me = new_node
            new_node.used_before_me = prior_node
        self._most_recent_count_nodes[new_count] = new_node

        lr_node = self._least_recent_count_nodes.get(new_count)
        previous_most_recent = self._most_recent_count_nodes.get(before_count)

        if not lr_node:
            self._least_recent_count_nodes[new_count] = new_node

        self._nodes_by_key[key] = new_node

        if self._min_count > new_count:
            self._min_count = new_count
        elif self._min_count == before_count and not previous_most_recent:
            self._min_count = new_count
    
    def _evict(self):
        c = self._min_count
        to_evict = self._least_recent_count_nodes.get(c)
        most_recent = self._most_recent_count_nodes.get(c)
        if to_evict:
            next_lru = to_evict.used_after_me
            self._least_recent_count_nodes[c] = next_lru
            if next_lru:
                next_lru.used_before_me = None
            if most_recent:
                if most_recent.key == to_evict.key:
                    del self._most_recent_count_nodes[c]
            del self._values[to_evict.key]
            del self._nodes_by_key[to_evict.key]
        print(self._least_recent_count_nodes,self._most_recent_count_nodes)
        # Note, the _min_count value may be inaccurate after this
        # however, this is only called when a new value is added,
        # which will necessarily reset the min count to 1.
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)