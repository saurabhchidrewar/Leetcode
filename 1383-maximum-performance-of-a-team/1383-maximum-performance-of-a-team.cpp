class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector <vector<int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({efficiency[i], speed[i]});
        }
        sort(arr.rbegin(), arr.rend());
        
        long speeds = 0, ans = 0, mod = 1e9 + 7;
        // MIN HEAP
        priority_queue <int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int s = arr[i][1], e = arr[i][0];
            pq.emplace(s);
            speeds += s;
            if (pq.size() > k) {
                speeds -= pq.top();
                pq.pop();
            }
            ans = max(ans, speeds * e);
        }
        return ans % mod;
    }
};