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
    TreeNode* construct(vector<int>& preorder, int i, int j) {
        if (i > j) return NULL;
        TreeNode* node = new TreeNode(preorder[i]);
        
        int k = i;
        while (k + 1 <= j && preorder[k+1] < preorder[i]) k++;
        node->left = construct(preorder, i+1, k);
        node->right = construct(preorder, k+1, j);
        
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size()-1);
    }
};