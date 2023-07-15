class Solution
{
    void addNode(Node *&head, Node *&tail, Node *&curr)
    {
        if (!head)
        {
            tail = curr;
            head = curr;
            curr = curr->next;
            tail->next = nullptr;
            return;
        }
        tail->next = curr;
        tail = tail->next;
        curr = curr->next;
        tail->next = nullptr;
    }

public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *zhead = nullptr, *ohead = nullptr, *thead = nullptr;
        Node *ztail = nullptr, *otail = nullptr, *ttail = nullptr;
        Node *curr = head;
        while (curr)
        {
            if (curr->data == 0)
            {
                addNode(zhead, ztail, curr);
            }
            else if (curr->data == 1)
            {
                addNode(ohead, otail, curr);
            }
            else
            {
                addNode(thead, ttail, curr);
            }
        }
        if (!zhead && !ohead)
            return thead;
        if (!ohead && !thead)
            return zhead;
        if (!zhead && !thead)
            return ohead;

        if (!zhead)
        {
            otail->next = thead;
            return ohead;
        }
        if (!ohead)
        {
            ztail->next = thead;
            return zhead;
        }
        if (!thead)
        {
            ztail->next = ohead;
            return zhead;
        }
        ztail->next = ohead;
        otail->next = thead;
        return zhead;
    }
};