/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseListNodes(ListNode *head)
        {
            ListNode *p = head, *q = head, *r = NULL;
            while (p)
            {
                q = p->next;
                p->next = r;
                r = p;
                p = q;
            }
            return r;
        }

    void mergeListNodes(ListNode *head1, ListNode *head2)
    {
        ListNode *p = head1, *q = head2;
        while (p)
        {
            ListNode *s = p->next;
            ListNode * t;
            if (q)
                t = q->next;
            p->next = q;
            p = s;
            if (q)
            {
                q->next = p;
                q = t;
            }
        }
    }

    void reorderList(ListNode *head)
    {
        ListNode *p = head;
        int n = 0;
        while (p)
        {
            p = p->next;
            n++;
        }
        int seperate;
        if (n % 2 == 1) seperate = n / 2 + 1;
        else seperate = n / 2;

        p = head;
        while (seperate--)
        {
            if (seperate == 0)
            {
                ListNode *q = p->next;
                p->next = NULL;
                p = q;
                continue;
            }
            p = p->next;
        }

        ListNode *head2 = reverseListNodes(p);
        mergeListNodes(head, head2);
    }
};