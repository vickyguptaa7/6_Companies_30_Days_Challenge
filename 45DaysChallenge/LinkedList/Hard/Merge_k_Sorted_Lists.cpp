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

struct Comp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
    void addNodeToTail(ListNode *&head, ListNode *&tail, ListNode *&node)
    {
        if (!head)
        {
            tail = node;
            head = node;
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Comp> pque;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                pque.push(lists[i]);
            }
        }
        ListNode *head = nullptr, *tail = nullptr;
        while (!pque.empty())
        {
            ListNode *curr = pque.top();
            pque.pop();
            addNodeToTail(head, tail, curr);
            if (curr)
            {
                pque.push(curr);
            }
        }
        return head;
    }
};