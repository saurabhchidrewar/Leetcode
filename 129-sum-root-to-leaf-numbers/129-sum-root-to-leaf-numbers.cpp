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
    void f(TreeNode* root, string temp) {
        
        if (root == NULL)
            return;
        
        temp += to_string(root->val);
        f(root->left, temp);
        // temp.pop_back();
        f(root->right, temp);
        // temp.pop_back();
        
        if (root && !root->left && !root->right) {
            int a = 0;
            long ind = 1;
            for (int i = temp.size()-1; ~i; i--) {
                a += (temp[i] - '0') * ind;
                ind *= 10;
            }
            cout << a << endl;
            ans += a;
            return;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        f(root, "");
        return ans;
    }
};