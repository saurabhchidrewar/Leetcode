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

// Two pass solution
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            len++;
            p = p -> next;
        }
        p = head;
        n = len - n - 1;
        if (n < 0) return head->next;
        while (n--) p = p->next;
        p->next = p->next->next;
        return head;
    }
};
*/

// Single pass solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head, *q = head;
        while (n--) p = p->next;
        if (p == NULL) return head->next;
        while (p->next) {
            q = q->next;
            p = p->next;
        }
        q->next = q->next->next;
        return head;
    }
};