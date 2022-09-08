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
    void solve(TreeNode* root, vector<int> &ino) {
        if (root == NULL) return;
        solve(root->left, ino);
        ino.push_back(root->val);
        solve(root->right, ino);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ino;
        solve(root, ino);
        return ino;
    }
};