class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            while (next && curr->val == next->val)
            {
                next = next->next;
            }
            curr->next = next;
            curr = curr->next;
        }
        return head;
    }
};