//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        map <int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        
        int ans = 0;
        
        vector <int> arr;
        for (auto it: mp) {
            arr.push_back(it.first);
        }
        
        n = arr.size();
        for (int i = n-1; ~i; i--) {
            ans += mp[arr[i]] * arr[i];
            if (i != 0) {
                if (mp.find(arr[i]-1) != mp.end())
                    mp[arr[i]-1] = max(mp[arr[i]-1] - mp[arr[i]], 0);
            }
            // cout << ans << " ";
        }
        
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends