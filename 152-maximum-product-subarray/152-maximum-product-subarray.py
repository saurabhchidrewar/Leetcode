class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Store the max Element
        curMin, curMax = 1, 1
        res = nums[0]
        
        for i in nums:
            curMax, curMin = max(curMax * i, curMin * i, i), min(curMax * i, curMin * i, i)
            res = max(res, curMax, curMin)
        
        return res