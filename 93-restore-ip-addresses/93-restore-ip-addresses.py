class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        if (n < 4 or n > 12):
            return []
        
        ans = []
        
        def isValid(temp):
            arr = temp.split('.')
            if (len(arr) < 4):
                return False
            for i in arr:
                if (len(i) > 1 and i[0] == '0'):
                    return False
                if (int(i) > 255):
                    return False
            return True
        
        for i in range(1, 4):
            for j in range(i+1, i+4):
                for k in range(j+1, j+4):
                    temp = ""
                    for v in range(n):
                        if (v == i or v == j or v == k):
                            temp += "."
                        temp += s[v]
                    if (isValid(temp)):
                        ans.append(temp)
                        
        return ans