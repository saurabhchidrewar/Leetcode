class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        s = s.lower()
        ans = []
        
        def traverse(i, t):
            if (i == len(s)):
                ans.append(t)
                return
            if (s[i] >= '0' and s[i] <= '9'):
                traverse(i + 1, t + s[i])
            else:
                traverse(i + 1, t + s[i])
                traverse(i + 1, t + s[i].upper())
        
        traverse(0, "")
        return ans