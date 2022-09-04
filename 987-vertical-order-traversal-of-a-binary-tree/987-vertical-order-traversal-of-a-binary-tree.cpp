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
    vector <vector<int>> vec;
    void traverse(TreeNode* root, int value, int level) {
        if (root == NULL)
            return;
        vec.push_back({value, level, root->val});
        traverse(root->left, value - 1, level + 1);
        traverse(root->right, value + 1, level + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        sort(vec.begin(), vec.end());
        vector <vector<vector<int>>> ans;
        // for (auto c : vec) {
        //     cout << c[0] << " " << c[1] << " " << c[2] << endl; 
        // }
        set <int> st;
        for (int i = 0; i < vec.size(); i++) {
            if (st.find(vec[i][0]) == st.end()) {
                st.insert(vec[i][0]);
                ans.push_back({{vec[i][1], vec[i][2]}});
            } else {
                ans[ans.size()-1].push_back({vec[i][1], vec[i][2]});
            }
        }
        vector <vector<int>> res;
        for (auto c : ans) {
            vector <int> level;
            for (auto i : c) {
                level.push_back(i[1]);
            }
            res.push_back(level);
        }
        return res;
    }
};