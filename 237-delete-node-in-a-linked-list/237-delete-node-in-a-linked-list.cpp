/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node->next;
        while (p) {
            node->val = p->val;
            if (p->next == NULL)
                node->next = NULL;
            node = p;
            p = p->next;
        }
    }
};