class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector <vector<int>> ans;
        for (int i = 0; i < m; i++) {
            vector <int> level;
            for (int j = 0; j < n; j++) {
                int val = min(rowSum[i], colSum[j]);
                rowSum[i] -= val;
                colSum[j] -= val;
                level.push_back(val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};