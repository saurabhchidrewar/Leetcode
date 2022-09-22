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
    set <int> to_delete_set;
    vector<TreeNode*> res;
    
    TreeNode* helper(TreeNode* root, bool isRoot) {
        if (root == NULL)
            return NULL; 
        
        bool found = to_delete_set.find(root->val) != to_delete_set.end();
        
        if (isRoot && !found) res.push_back(root);
        
        root->left = helper(root->left, found);
        root->right = helper(root->right, found);
        
        if (found) return NULL;
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto &c: to_delete) to_delete_set.insert(c);
        helper(root, true);
        return res;
    }
};