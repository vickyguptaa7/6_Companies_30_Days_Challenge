/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    int findLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            head = head->next;
            len++;
        }
        return len;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = findLength(headA);
        int lengthB = findLength(headB);
        if (lengthA < lengthB)
            return getIntersectionNode(headB, headA);
        int diff = lengthA - lengthB;
        while (diff--)
        {
            headA = headA->next;
        }
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};