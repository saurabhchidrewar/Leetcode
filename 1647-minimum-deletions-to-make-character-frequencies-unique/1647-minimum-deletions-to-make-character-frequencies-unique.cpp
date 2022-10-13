class Solution {
public:
    int minDeletions(string s) {
        unordered_map <char, int> mp;
        for (auto c: s) mp[c]++;
        
        vector <int> arr;
        for (auto it: mp) {
            arr.push_back(it.second);
        }
        
        int ans = 0;
        sort(arr.rbegin(), arr.rend());
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i-1]) {
                if (arr[i-1] == 0) {
                    ans += arr[i];
                    arr[i] = 0;
                } else {
                    ans += (arr[i] - arr[i-1] + 1);
                    arr[i] = arr[i-1] - 1;
                }
            }
        }
        
        return ans;
    }
};