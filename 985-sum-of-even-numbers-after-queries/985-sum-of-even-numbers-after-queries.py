class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        es = sum([i for i in nums if i % 2 == 0])
        ans = []
        for v,i in queries:
            latest = nums[i] + v
            if (nums[i] % 2 == 0):
                if (abs(latest) % 2 == 0):
                    es += v
                else:
                    es -= nums[i]
            else:
                if (abs(latest) % 2 == 0):
                    es += (nums[i] + v)
            
            nums[i] = latest
            ans.append(es)
        
        return ans