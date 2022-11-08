//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int mn = INT_MAX, sum = 0;
	    for (int i= 0; i<n ; i++) sum+=arr[i];
	    
	    bool dp[n+1][sum+1];
	    
	    for (int i=0; i<n+1 ;i++)
	    {
	        for (int j=0; j< sum+1; j++)
	        {
	            if (i == 0 || j == 0) 
	            {
	                if (i == 0) dp[i][j] = false;
	                if (j == 0) dp[i][j] = true;
	            }
	            else
	            {
	                if (arr[i-1] <= j) 
	                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    	           else
    	            dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    vector <int> v;
	    for (int i = 0; i < sum; i++) 
	    {
	        if (dp[n][i]) v.push_back(i);
	    }
	    
	    for (int i=0; i<v.size()/2+1; i++)
	    {
    	   mn = min(mn , sum - 2*v[i]);
	    }
	    
	    return mn;
	}

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends