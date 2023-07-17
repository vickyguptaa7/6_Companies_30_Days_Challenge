void addNodeToTail(Node *&head, Node *&tail, Node *&node)
{
    if (!head)
    {
        tail = node;
        head = node;
        node = node->bottom;
        tail->bottom = nullptr;
        return;
    }
    tail->bottom = node;
    tail = tail->bottom;
    node = node->bottom;
    tail->bottom = nullptr;
}

Node *mergeList(Node *head1, Node *head2)
{
    Node *head = nullptr, *tail = nullptr;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            addNodeToTail(head, tail, head1);
        }
        else
        {
            addNodeToTail(head, tail, head2);
        }
    }
    while (head1)
    {
        addNodeToTail(head, tail, head1);
    }
    while (head2)
    {
        addNodeToTail(head, tail, head2);
    }
    return head;
}

Node *flatten(Node *root)
{
    if (!root || !root->next)
        return root;
    Node *curr = nullptr;
    while (root)
    {
        Node *next = root->next;
        curr = mergeList(curr, root);
        root = next;
    }
    return curr;
}