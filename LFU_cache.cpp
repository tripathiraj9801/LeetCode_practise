class LFUCache
{
public:
    LFUCache(int capacity_)
    {
        capacity = capacity_;
    }
    struct UC
    {
        int value;
        multimap<int, int>::iterator it;
    };
    int get(int key)
    {
        auto f = dict.find(key);
        if (f == dict.end())
        {
            return -1;
        }

        increaseUseCounter(f);
        return f->second.value;
    }

    void put(int key, int value)
    {
        auto f = dict.find(key);

        if (f == dict.end())
        {
            insertNewKey(key, value);
        }
        else
        {
            f->second.value = value;
            increaseUseCounter(f);
        }
    }

private:
    void popLeastFreqUsed()
    {
        auto lfu = keysByUseCounter.begin();
        assert(lfu != keysByUseCounter.end());
        auto f = dict.find(lfu->second);
        assert(f != dict.end());
        dict.erase(f);
        keysByUseCounter.erase(lfu);
    }

    void insertNewKey(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }

        while (dict.size() >= capacity)
        {
            popLeastFreqUsed();
        }
        auto it = keysByUseCounter.insert({1, key});
        dict.insert({key,
                     {value,
                      it}});
    }

    void increaseUseCounter(const unordered_map<int, UC>::iterator dictIt)
    {
        auto extracted = keysByUseCounter.extract(dictIt->second.it);
        extracted.key() += 1;
        dictIt->second.it = keysByUseCounter.insert(move(extracted));
    }

    int capacity;
    unordered_map<int, UC> dict;
    multimap<int, int> keysByUseCounter;
};