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


// My Solution 


class Solution {
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int a = solve(root->left);
        if (a == 0)
            root->left = NULL;
        int b = solve(root->right);
        if (b == 0)
            root->right = NULL;
        return a + b + root->val; 
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        if (root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;
        return root;
    }
};


// Optimised
// class Solution {
// public:
//     TreeNode* pruneTree(TreeNode* root) {
//         if (root == NULL)
//             return NULL;
        
//         root->left = pruneTree(root->left);
//         root->right = pruneTree(root->right);
        
//         if (!root->left && !root->right && root->val == 0)
//             return NULL;
        
//         return root;
//     }
// };