/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue <TreeNode*> q;
        vector <int> arr;
        if (root == NULL) return arr;
        q.push(root);
        while (!q.empty()) {
            int mx = INT_MIN, n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                mx = max(mx, node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            arr.push_back(mx);
        }
        return arr;
    }
};