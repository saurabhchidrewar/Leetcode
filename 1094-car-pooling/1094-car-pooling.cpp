class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1005]{};
        for (auto c: trips) {
            for (int i = c[1]; i < c[2]; i++) {
                arr[i] += c[0];
                if (arr[i] > capacity) return false;
            }
        }
        return true;
    }
};