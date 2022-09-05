/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map <Node*, Node*> mp;
        Node* t = head;
        Node* root = new Node(0);
        Node* p = root;
        while (t) {
            Node* temp = new Node(t->val);
            p->next = temp;
            p = temp;
            mp[t] = p;
            t = t->next;
        }
        p->next = NULL;
        t = head, p = root->next;
        while (t) {
            p->random = mp[t->random];
            t = t->next;
            p = p->next;
        }
        return root->next;
    }
};