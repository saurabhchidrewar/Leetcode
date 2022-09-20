class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        arr1 = version1.split('.')
        arr2 = version2.split('.')
        
        diff = abs(len(arr1) - len(arr2))
        if (len(arr1) < len(arr2)):
            arr1.extend(['0'] * diff)
        elif (len(arr1) > len(arr2)):
            arr2.extend(['0'] * diff)
        
        mx1, mx2 = max([len(i) for i in arr1]), max([len(i) for i in arr2])
        mx = max(mx1, mx2)
        
        n = len(arr1)
        
        for i in range(n):
            arr1[i].zfill(mx)
            arr2[i].zfill(mx)
            s1 = arr1[i]
            s2 = arr2[i]
            if (int(s1) < int(s2)):
                return -1
            elif (int(s1) > int(s2)):
                return 1
        
        return 0
            
            