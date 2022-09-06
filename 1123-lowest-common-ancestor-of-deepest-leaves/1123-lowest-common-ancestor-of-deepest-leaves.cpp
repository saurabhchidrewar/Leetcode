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

// Refer:  https://www.youtube.com/watch?v=Fl0fIKfTZKA
class Solution {
    pair <TreeNode*, int> f(TreeNode* root) {
        if (root == NULL) {
            return {root, 0};
        }
        
        auto l = f(root->left);
        auto r = f(root->right);
        
        int a = l.second, b = r.second;
        if (a == b)
            return {root, a + 1};
        else if (a > b)
            return {l.first, a + 1};
        else
            return {r.first, b + 1};
        
        return {root, max(a,b) + 1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return (f(root)).first;
    }
};