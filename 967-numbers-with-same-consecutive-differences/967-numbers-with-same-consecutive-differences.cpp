class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector <int> arr = {1,2,3,4,5,6,7,8,9};
        for (int i = 1; i < n; i++) {
            vector <int> arr2;
            for (auto c: arr) {
                int x = c % 10;
                if (x + k < 10)
                    arr2.push_back(c * 10 + (x + k));
                if (k > 0 && x - k >= 0)
                    arr2.push_back(c * 10 + (x - k));
            }
            arr = arr2;
        }
        return arr;
    }
};