// Problem Link https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *temp = head;
        for (int i = 0; i < k; i++)
        {
            if (temp == nullptr)
                return head;
            temp = temp->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        int count = 0;

        while (curr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};