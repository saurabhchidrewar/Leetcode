class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1 = sorted(s1)
        s2 = sorted(s2)
        ans1, ans2 = 0, 0
        for i in range(len(s1)):
            if (s1[i] >= s2[i]):
                ans1 += 1
            if (s2[i] >= s1[i]):
                ans2 += 1
            # print(ans1, ans2)
        return ans1 == len(s1) or ans2 == len(s2)