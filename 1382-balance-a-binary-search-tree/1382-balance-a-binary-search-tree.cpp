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
    TreeNode* construct(vector <TreeNode*> &arr, int i, int j) {
        if (i > j)
            return NULL;
        
        int n = (i + j) / 2;
        TreeNode *node = arr[n];
        node->left = construct(arr, i, n-1);
        node->right = construct(arr, n+1, j);
        return node;
    } 
    
    void inorder(TreeNode* root, vector <TreeNode*> &in) {
        if (root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector <TreeNode*> in;
        inorder(root, in);
        return construct(in, 0, in.size()-1);
    }
};