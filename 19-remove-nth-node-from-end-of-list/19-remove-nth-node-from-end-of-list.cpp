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