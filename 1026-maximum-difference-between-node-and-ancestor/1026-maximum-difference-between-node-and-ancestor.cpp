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
    int solve(TreeNode* root, int low, int high, int temp) {
        if (root == NULL) {
            return temp;
        }
        
        low = min(low, root->val);
        high = max(high, root->val);
        int a = solve(root->left, low, high, high - low);
        int b = solve(root->right, low, high, high - low);
        return max(a,b);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = solve(root, 1e5 + 2, -1, 0);
        return ans;
    }
};