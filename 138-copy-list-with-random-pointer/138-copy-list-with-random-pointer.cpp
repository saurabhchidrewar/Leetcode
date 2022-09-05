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

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
           	// Iterate 2 times 
           	// First iteration : Create the linked list without random 
            //                   pointers and map new node  with the old node
           	// Second iteration: In the newly created list connect random 
            //                   pointers using the generated map

            map<Node*, Node*> mp;
            Node *t = head;
            Node *root = new Node(0);
            Node *p = root;
            while (t)
            {
                Node *temp = new Node(t->val);
                p->next = temp;
                p = temp;
                mp[t] = p;	
                // Map new node with the old node such 
                // that we can correlate random pointer in next pass
                t = t->next;
            }
            p->next = NULL;
            t = head, p = root->next;
            while (t)
            {
                p->random = mp[t->random];
                t = t->next;
                p = p->next;
            }
            return root->next;
        }
};