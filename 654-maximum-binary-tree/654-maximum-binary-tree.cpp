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
    int findMax(vector<int>& nums, int i, int j) {
        int mx = INT_MIN, ind = -1;
        for (int k = i; k <= j; k++) {
            if (nums[k] > mx) {
                mx = nums[k];
                ind = k;
            }
        }
        return ind;
    }
    
    TreeNode* buildTree(vector<int>& nums, int i, int j) {
        if (i > j) return NULL;
        if (i == j) return new TreeNode(nums[i]);
        
        int ind = findMax(nums, i, j);
        TreeNode* node = new TreeNode(nums[ind]);
        node->left = buildTree(nums, i, ind-1);
        node->right = buildTree(nums, ind+1, j);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};