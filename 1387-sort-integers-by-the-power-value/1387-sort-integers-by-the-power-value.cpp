class Solution {
    unordered_map <int,int> mp;
    int solve(int n) {
        if (n == 1) return 0;
        if (mp.find(n) != mp.end()) return mp[n];
        int a;
        if (n % 2 == 0) a = n / 2;
        else a = n * 3 + 1;
        return mp[n] = 1 + solve(a);
    }
public:
    int getKth(int lo, int hi, int k) {
        // memset(dp, -1, sizeof(dp));
        vector <pair<int,int>> ans;
        for (int i = lo; i <= hi; i++) {
            int a = solve(i);
            // cout << a << endl;
            ans.push_back({a, i});
            
        }
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};