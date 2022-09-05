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

class Solution
{
    map<TreeNode*, bool> mp;
    bool isBST(TreeNode *root, long mn, long mx)
    {
        if (root == NULL)
            return true;

        if (mp.find(root) != mp.end())
            return mp[root];

        if ((root->val >= mx) || (root->val <= mn))
            return mp[root] = false;

        bool a = isBST(root->left, mn, root->val);
        if (!a) return mp[root] = false;

        bool b = isBST(root->right, root->val, mx);
        if (!b) return mp[root] = false;

        return mp[root] = true;
    }
    public:
        bool isValidBST(TreeNode *root)
        {
            return isBST(root, LONG_MIN, LONG_MAX);
        }
};