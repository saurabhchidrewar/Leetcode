/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector <vector<int>> bfs;
        queue <Node*> q;
        if (root == NULL)
            return bfs;
        q.push(root);
        while (!q.empty()) {
            vector <int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                level.push_back(node->val);
                q.pop();
                for (int j = 0; j < (node->children).size(); j++) {
                    q.push((node->children)[j]);
                }
            }
            bfs.push_back(level);
        }
        return bfs;
    }
};