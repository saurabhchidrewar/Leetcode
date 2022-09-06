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
    TreeNode* ans;
    int f(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = f(root->left);
        int r = f(root->right);
        
        if (l == r) ans = root;
        else if (l < r) f(root->right);
        else f(root->left);
        
        return max(l,r) + 1;
    } 
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        f(root);
        return ans;
    }
};