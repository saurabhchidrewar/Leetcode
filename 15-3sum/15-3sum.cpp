class Solution {
    int maxElement(vector <int> &arr) {
        int a = INT_MIN, b = INT_MAX;
        for (auto &c : arr) {
            a = max(a, c);
            b = min(b, c);
        }
        if (a == b && a == 0)
            return 0;
        return 1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector <vector<int>> ans;
        if (maxElement(arr) == 0) {
            ans.push_back({0,0,0});
            return ans;
        }
        set <vector<int>> temp;
        int  n = arr.size();
        sort(arr.begin(), arr.end());
        for (int a = 0; a < n-2; a++) {
            int b = a+1, c = n-1;
            while (b < c) {
                int sm = arr[a] + arr[b] + arr[c];
                if (sm == 0) {
                    vector <int> vals;
                    vals.push_back(arr[a]);
                    vals.push_back(arr[b]);
                    vals.push_back(arr[c]);
                    temp.insert(vals);
                }
                if (sm < 0)
                    b++;
                else
                    c--;
            }
        }
        for (auto c: temp) ans.push_back(c);
        return ans;
    }
};