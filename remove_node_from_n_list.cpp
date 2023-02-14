// Problem Link https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *Reverse(ListNode *&head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != NULL)
        {
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *temp1 = Reverse(head);
        ListNode *temp = temp1;
        if (n == 1)
        {
            ListNode *del = temp1;
            temp1 = temp1->next;
            delete del;
        }
        else
        {

            for (int i = 0; i < n - 2; i++)
            {
                temp = temp->next;
            }
            ListNode *flag = temp->next;
            temp->next = flag->next;
            delete flag;
        }
        ListNode *ret = Reverse(temp1);
        return ret;
    }
};

// Solution in Java programi