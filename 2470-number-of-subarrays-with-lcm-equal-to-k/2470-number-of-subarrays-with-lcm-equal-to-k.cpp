class Solution {
    int findLCM(int a, int b) {
        return a*b / gcd(a,b);
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            for (int j = i; j < nums.size(); j++) {
                curr = findLCM(curr, nums[j]);
                if (curr == k) ans++;
                else if (curr > k) break;
            }
        }
        return ans;
    }
};