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

/*
class Solution {
    bool isBST(TreeNode* root, long mn, long mx) {
        if (root == NULL)
            return true;

        if ((root->val >= mx) || (root->val <= mn))
            return false;

        bool a = isBST(root->left, mn, root->val);
        if (!a) return false;

        bool b = isBST(root->right, root->val, mx);
        if (!b) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
*/

// Inorder traversal of BST is sorted
class Solution
{       
    vector <int> inorder;
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        traverse(root);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i-1])
                return false;
        }
        return true;
    }
};