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
    void addNodeToTail(ListNode *&head, ListNode *&tail, ListNode *&node)
    {
        if (!head)
        {
            head = node;
            tail = node;
            node = node->next;
            tail->next = nullptr;
            return;
        }
        tail->next = node;
        tail = tail->next;
        node = node->next;
        tail->next = nullptr;
    }

public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *oddHead = nullptr, *evenHead = nullptr;
        ListNode *oddTail = nullptr, *evenTail = nullptr;
        ListNode *curr = head;
        int indx = 1;
        while (curr)
        {
            if (indx & 1)
            {
                addNodeToTail(oddHead, oddTail, curr);
            }
            else
            {
                addNodeToTail(evenHead, evenTail, curr);
            }
            indx++;
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};