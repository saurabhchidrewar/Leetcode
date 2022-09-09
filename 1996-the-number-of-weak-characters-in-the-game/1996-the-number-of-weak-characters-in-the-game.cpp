class Solution {
    static bool comp(vector <int> &v1, vector <int> &v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size(), ans = 0;
        int arr[n];
        for (int i = n-1; ~i; i--) {
            if (i == n-1) arr[i] = properties[i][1];
            else arr[i] = max(arr[i+1], properties[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (properties[i][1] < arr[i]) ans++;
        }
        return ans;
    }
};