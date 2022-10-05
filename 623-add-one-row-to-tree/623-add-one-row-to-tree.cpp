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
    void dfs(TreeNode* root, int val, int depth, int level) {
        if (root == NULL)
            return;
        
        if (level == depth - 1) {
            // if (root->left) {
                TreeNode* l = root->left;
                TreeNode* node = new TreeNode(val);
                root->left = node;
                node->left = l;
            // }
            // if (root->right) {
                TreeNode* r = root->right;
                node = new TreeNode(val);
                root->right = node;
                node->right = r;
            // }
        }
        dfs(root->left, val, depth, level + 1);
        dfs(root->right, val, depth, level + 1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root, val, depth, 1);
        return root;
    }
};