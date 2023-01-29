// Problem Link https://leetcode.com/problems/swap-nodes-in-pairs/description/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *prev = dummyNode;
        while (curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return dummyNode->next;
    }
};