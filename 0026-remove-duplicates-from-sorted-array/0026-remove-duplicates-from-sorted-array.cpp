class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int i=1,current=1;
        for (i=1;i<nums.size();i++)
        {
            if (nums[i]!=nums[i-1]){
                nums[current]=nums[i];
                current++;
            }
        }
        return current;
    }
};