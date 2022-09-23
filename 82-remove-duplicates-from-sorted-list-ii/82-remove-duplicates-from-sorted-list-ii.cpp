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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        set <int> s;
        while (p) {
            if (p->next && p->next->val == p->val) {
                p->next = p->next->next;
                s.insert(p->val);
            } else {
                p = p->next;
            }
        }
        p = head;
        ListNode* prev = NULL;
        while (p) {
            if (s.find(p->val) != s.end()) {
                if (prev == NULL) {
                    head = head->next;
                }
                else {
                    prev->next = p->next;
                }
                p = p->next;
                continue;
            }
            if (prev == NULL)
                prev = p;
            else 
                prev = prev->next;
            p = p->next;
        }
        return head;
    }
};