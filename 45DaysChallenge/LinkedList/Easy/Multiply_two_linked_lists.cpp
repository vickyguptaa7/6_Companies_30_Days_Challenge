long long linkedListNumber(Node *head)
{
    long long num = 0, mod = 1e9 + 7;
    while (head)
    {
        num = num * 10 + (head->data);
        num %= mod;
        head = head->next;
    }
    return num;
}

long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long num1 = linkedListNumber(l1), num2 = linkedListNumber(l2), mod = 1e9 + 7;
    return (num1 * num2) % mod;
}