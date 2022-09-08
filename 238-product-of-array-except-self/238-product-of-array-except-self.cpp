class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> ans;
        int left = 1, right = 1;
        for (int i=0; i<nums.size(); i++)
        {
            if (i == 0)
            {
                ans.push_back(1);
            }
            else
            {
                left *= nums[i-1];
                ans.push_back(left);        
            } 
        }
        
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (i != nums.size()-1)
            {
                right *= nums[i+1];
                ans[i] *= right;        
            } 
        }
        return ans;
    }
};