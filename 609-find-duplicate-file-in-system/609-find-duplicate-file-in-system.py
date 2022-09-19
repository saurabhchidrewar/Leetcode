class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        for path in paths:
            arr = path.split()
            for j in arr[1:]:
                ind = j.find('(')
                if (j[ind+1:-1] not in d.keys()):
                    d[j[ind+1:-1]] = [arr[0] + "/" +j[:ind]]
                else:
                    d[j[ind+1:-1]].append(arr[0] + "/" + j[:ind])
        ans = [i for i in d.values() if len(i) > 1]
        return ans