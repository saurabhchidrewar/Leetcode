class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key = lambda x: (x[0], -x[1]))
        ans = [people[-1]]
        n = len(people)
        for i in range(n-2, -1, -1):
            # print(ans)
            ans.insert(people[i][1],people[i])
        return ans