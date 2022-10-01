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
public:
    int maxLevelSum(TreeNode* root) {
        int anslevel = 0, count = INT_MIN, currLevel = 0;
        queue <TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            currLevel++;
            int n = q.size();
            int levelSum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                levelSum += node->val;
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (levelSum > count) {
                anslevel = currLevel;
                count = levelSum;
            }
        }
        
        return anslevel;
    }
};