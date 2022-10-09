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
    vector <int> in;
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = in.size() - 1;
        while (i < j) {
            if (in[i] + in[j] == k) return true;
            if (in[i] + in[j] > k) j--;
            else i++;
        }
        return false;
    }
};