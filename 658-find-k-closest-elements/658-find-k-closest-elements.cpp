class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <vector<int>> store;
        for (auto &c: arr) {
            store.push_back({abs(c - x), c});
        }
        sort(store.begin(), store.end());
        vector <int> ans;
        for (auto &c: store) {
            if (k--) {
                ans.push_back(c[1]);
            } else {
                break;
            }
        } 
        sort(ans.begin(), ans.end());
        return ans;
    }
};