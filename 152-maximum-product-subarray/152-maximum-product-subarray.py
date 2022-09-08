# Refer : https://www.youtube.com/watch?v=lXVy6YWFcRM

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curMin, curMax = 1, 1
        res = nums[0]
        
        for i in nums:
            temp = curMax * i
            curMax = max(temp, curMin * i, i)
            curMin = min(temp, curMin * i, i)
            res = max(res, curMax, curMin)
        
        return res