class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};