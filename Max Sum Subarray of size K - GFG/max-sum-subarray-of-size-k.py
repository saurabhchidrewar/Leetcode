#User function Template for python3
class Solution:
    def maximumSumSubarray (self,K,Arr,N):
        # code here
        ans = sum(Arr[:K])
        val, i, j = ans, 0, K-1
        while (j != N-1):
            val -= Arr[i]
            i+=1
            j+=1
            val += Arr[j]
            ans = max(ans, val)
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        N,K = input().split()
        N = int(N)
        K = int(K)
        Arr = list( map(int,input().strip().split(" ")))

        ob = Solution()
        print(ob.maximumSumSubarray(K,Arr,N))
# } Driver Code Ends