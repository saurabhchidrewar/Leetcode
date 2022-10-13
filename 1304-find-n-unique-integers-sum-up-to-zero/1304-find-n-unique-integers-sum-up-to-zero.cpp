class Solution {
public:
    vector<int> sumZero(int n) {
        int sm = 0;
        vector <int> ans;
        for (int i = 1; i < n; i++) {
            ans.push_back(i);
            sm += i;
        }
        ans.push_back(sm * -1);
        return ans;
    }
};