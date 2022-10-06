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
    bool removeLeaf(TreeNode* root, int target) {
        if (root == NULL)
            return false;
        
        if (removeLeaf(root->left, target)) 
            root->left = NULL;

        if (removeLeaf(root->right, target)) 
            root->right = NULL;
        
        if (!root->left && !root->right && root->val == target) 
            return true;
        
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL)
            return NULL;
        if (removeLeaf(root, target)) 
            return NULL;
        return root;
    }
};