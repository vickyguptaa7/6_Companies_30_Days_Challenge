class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        ListNode *slow = head, *fast = head;
        do
        {
            if (!fast || !fast->next)
                break;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        return slow == fast;
    }
};