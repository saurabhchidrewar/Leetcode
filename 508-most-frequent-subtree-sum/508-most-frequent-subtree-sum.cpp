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
    unordered_map <int,int> mp;
    int mx = 0;
    int traverse(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int l = traverse(root->left);
        int r = traverse(root->right);
        
        int sm = (root->val) + l + r;
        mp[sm]++;
        mx = max(mx, mp[sm]);
        return sm;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        vector <int> ans;
        for (auto &c: mp) {
            if (c.second == mx) {
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};