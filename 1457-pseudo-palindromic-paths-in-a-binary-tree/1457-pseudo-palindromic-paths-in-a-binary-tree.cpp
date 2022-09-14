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
    void traverse(TreeNode* root, unordered_map <int,int> &mp, int count) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (mp[root->val] % 2 == 0)
                count++;
            else 
                count--;
            mp[root->val]++;
            // for (auto c: mp) cout << c.first << " " << c.second << " " << count << endl;
            // cout << endl;
            if (count <= 1) ans++;
            mp[root->val]--;
            return;
        }
        
        if (mp[root->val] % 2 == 0)
            count++;
        else 
            count--;
        mp[root->val]++;
        traverse(root->left, mp, count);
        traverse(root->right,mp, count);
        mp[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map <int,int> mp;
        traverse(root, mp, 0);
        return ans;
    }
};