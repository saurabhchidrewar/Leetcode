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
    bool isEvenOddTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            int prev = -1;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                int v = node->val;
                if (level % 2 == v % 2) 
                    return false;
                if (prev != -1) {              
                    if (level % 2 == 0 && prev >= v) 
                        return false;
                    if (level % 2 == 1 && prev <= v) 
                        return false;
                }
                prev = v;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};