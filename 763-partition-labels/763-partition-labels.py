class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        start, end = 0, 0
        for i in range(len(s)):
            end = max(end, s.rfind(s[i]))
            if (i == end):
                ans.append(end - start + 1)
                start = i + 1
        return ans