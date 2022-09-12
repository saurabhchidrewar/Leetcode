/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

/*
// O(n) Solution

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int a = 0, b = 0;
        if (root->left)
            a = countNodes(root->left);
        if (root->right)
            b = countNodes(root->right);

        return 1 + a + b;
    }
};
*/

// Optimal 
// TC : O(log(n) *log(n))

class Solution
{
    public:
        int countNodes(TreeNode *root)
        {
            if (root == NULL) return 0;

            int lh = leftHeight(root);
            int rh = rightHeight(root);

            if (lh == rh) return (1 << lh) - 1;
           	// (1 << lh - 1) == pow(lh, 2) - 1

            return 1 + countNodes(root->left) + countNodes(root->right);
        }

    int leftHeight(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }

    int rightHeight(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
};