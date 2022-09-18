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
    vector <int> inorder;
    void in(TreeNode* root) {
        if (root == NULL)
            return;
        
        in(root->left);
        inorder.push_back(root->val);
        in(root->right);
    }
    
    void solve(TreeNode* root1, TreeNode* root2, vector <int> &ans) {
        in(root1);
        vector <int> arr1 = inorder;
        inorder.clear();
        in(root2);
        vector <int> arr2 = inorder;
        // return ans;
        
        int i = 0, j = 0;
        while (i != arr1.size() && j != arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while (j != arr2.size()) {
            ans.push_back(arr2[j]);
            j++;
        }
        
        while (i != arr1.size()) {
            ans.push_back(arr1[i]);
            i++;
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> ans;
        solve(root1, root2, ans);
        return ans;
    }
};