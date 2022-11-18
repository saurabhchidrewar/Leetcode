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
    int minSwaps(vector<int>&nums) {
	    vector <pair<int, int>> arr;
	    for (int i = 0; i < nums.size(); i++) {
	        arr.push_back({nums[i], i});
	    }
	    sort(arr.begin(), arr.end());    
	    int ans = 0;
	    for (int i = 0; i < nums.size(); i++) {
	        if (arr[i].second == i) continue;
	        else {
	            ans++;
	            swap(arr[i], arr[arr[i].second]);
	            i--;
	        }
	    }
	    return ans;
	}
public:
    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector <int> level;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                int v = node->val;
                level.push_back(v);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res += minSwaps(level);
        }
        return res;
    }
};