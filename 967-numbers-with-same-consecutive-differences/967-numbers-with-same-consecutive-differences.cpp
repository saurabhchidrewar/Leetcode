class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        self.ans=set()
        def recur(s):
            if k==0 and s[-1]=='0':
                return
            if len(s)==n and s[0]!='0':
                self.ans.add(int(s))
                return
            if len(s)==n+1 and s[0]=='0':
                self.ans.add(int(s))
                return
            
            x=int(s[-1])+k
            y=int(s[-1])-k
            
            if 0<=x<10:
                recur(s+str(x))
            if 0<=y<10:
                recur(s+str(y))
        for i in range(10):
            recur(str(i))
        return list(self.ans)