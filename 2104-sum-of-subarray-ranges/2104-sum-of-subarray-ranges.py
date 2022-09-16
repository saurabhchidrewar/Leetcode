class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            mx = nums[i]
            mn = nums[i]
            for j in range(i+1, len(nums)):
                mx = max(mx, nums[j])
                mn = min(mn, nums[j])
                ans += (mx - mn)
        return ans