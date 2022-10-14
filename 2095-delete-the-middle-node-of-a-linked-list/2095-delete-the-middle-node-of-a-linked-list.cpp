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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (slow && fast) {
            if (fast->next)
                fast = fast->next->next;
            else
                break;
            slow = slow->next;
            // cout << slow->val << " " << fast->val << endl;
        } 
        if (head == slow) return head->next;
        
        ListNode* t = head;
        while (t->next != slow) t = t->next;
        t->next = slow->next;
        
        return head;
    }
};