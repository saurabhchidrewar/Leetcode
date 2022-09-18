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
    
    vector <int> solve(TreeNode* root1, TreeNode* root2) {
        in(root1);
        in(root2);
        sort(inorder.begin(), inorder.end());
        return inorder;
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};