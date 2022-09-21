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
    TreeNode* parent = NULL;
    void traverse(TreeNode* root, TreeNode* node) {
        if (root->val > node->val) {
            if (root->left == NULL)
                root->left = node;
            else
                traverse(root->left, node);
        }
        
        if (root->val < node->val) {
            if (root->right == NULL)
                root->right = node;
            else
                traverse(root->right, node);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        TreeNode* node = new TreeNode(data);
        if (root == NULL)
            return node;
        
        traverse(root, node);
        return root;
    }
};