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
    string ans;
    string reverseStr(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    
    void traverse(TreeNode* root, string temp) {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            char c = 'a' + root->val;
            temp += c;
            string t = reverseStr(temp);
            if (ans == "") ans = t;
            else 
               ans = min(ans, t);
            return;
        }
        
        char ch = 'a' + root->val;
        temp += ch;
        traverse(root->left, temp);
        traverse(root->right, temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        traverse(root, "");
        return ans;
    }
};