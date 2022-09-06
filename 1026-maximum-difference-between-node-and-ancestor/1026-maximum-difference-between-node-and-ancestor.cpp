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
    int ans = 0;
    void solve(TreeNode* root, int low, int high) {
        if (root == NULL) {
            ans = max(ans, high - low);
            return;
        }
        
        low = min(low, root->val);
        high = max(high, root->val);
        solve(root->left, low, high);
        solve(root->right, low, high);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        solve(root, 1e5 + 2, -1);
        return ans;
    }
};