// Using Maps
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        map<Node *, Node *> mpp;
        Node *curr = head->next, *nhead = new Node(head->val), *tail = nhead;
        mpp[head] = nhead;
        while (curr)
        {
            tail->next = new Node(curr->val);
            tail = tail->next;
            mpp[curr] = tail;
            curr = curr->next;
        }
        curr = head;
        Node *ncurr = nhead;
        while (curr)
        {
            ncurr->random = mpp[curr->random];
            curr = curr->next;
            ncurr = ncurr->next;
        }
        return nhead;
    }
};

// Without Map
/*
First make the node copy and add next to the list
eg original list a b c d e f g h
modified list a a` b b` c c` d d` e e` ...

Then add the random node pointer to the list
will be a->next ->random=a->random->next
a->next corresponds to a`
a->random->next corresponds to some random node modified node

Now just remove the added node from the list and create a new list
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            else
            {
                curr->next->random = nullptr;
            }
            curr = curr->next->next;
        }
        curr = head->next;
        Node *nhead = head->next;
        while (curr && curr->next)
        {
            head->next = curr->next;
            head = head->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        head->next = nullptr;
        return nhead;
    }
};