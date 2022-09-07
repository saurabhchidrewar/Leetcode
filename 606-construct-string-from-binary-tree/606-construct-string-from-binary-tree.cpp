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
    string ans;
    void f(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (ans.size())
            ans += "(";
        ans += to_string(root->val);
        if (root->left == NULL && root->right) ans += "()";
        f(root->left);
        f(root->right);
        ans += ")";
    }
    public:
        string tree2str(TreeNode *root)
        {
            f(root);
            ans.pop_back();
            return ans;
        }
};