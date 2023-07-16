class Solution
{
    Node *reverseList(Node *head)
    {
        Node *curr = head, *prev = nullptr, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *findMiddle(Node *head)
    {
        Node *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    void reorderList(Node *head)
    {
        Node *middle = findMiddle(head);
        Node *right = reverseList(middle->next);
        middle->next = nullptr;
        Node *left = head->next, *curr = head;
        while (left && right)
        {
            curr->next = right;
            right = right->next;
            curr = curr->next;
            curr->next = nullptr;
            if (left)
            {
                curr->next = left;
                left = left->next;
                curr = curr->next;
                curr->next = nullptr;
            }
        }
        if (right)
        {
            curr->next = right;
            right = right->next;
            curr = curr->next;
            curr->next = nullptr;
        }
    }
};