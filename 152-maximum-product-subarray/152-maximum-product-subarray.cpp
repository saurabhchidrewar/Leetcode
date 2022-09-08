class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = 1, currMax = 1;
        int result = *max_element(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++)
        {
            int temp = currMax * nums[i];
            currMax = max( currMax * nums[i], max( currMin * nums[i], nums[i]) );
            currMin = min( temp, min( currMin * nums[i], nums[i]) );
            result = max(result, currMax);
        }
        
        return result;
    }
};