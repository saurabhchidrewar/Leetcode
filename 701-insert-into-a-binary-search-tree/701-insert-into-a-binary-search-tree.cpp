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
    void traverse(TreeNode* root, int data) {
        if (root->val > data) {
            if (root->left == NULL) 
                parent = root;
            else
                traverse(root->left, data);
        }
        
        if (root->val < data) {
            if (root->right == NULL)
                parent = root;
            else
                traverse(root->right, data);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        TreeNode* node = new TreeNode(data);
        if (root == NULL)
            return node;
        
        traverse(root, data);
        if (parent->val > data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        
        return root;
    }
};