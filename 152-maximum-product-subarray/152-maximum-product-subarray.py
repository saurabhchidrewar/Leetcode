class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Store the max Element
        curMin, curMax = 1, 1
        res = nums[0]
        
        for i in nums:
            temp = curMax * i
            curMax = max(temp, curMin * i, i)
            curMin = min(temp, curMin * i, i)
            res = max(res, curMax, curMin)
        
        return res