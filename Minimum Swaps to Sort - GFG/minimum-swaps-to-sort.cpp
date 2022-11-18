//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector <pair<int, int>> arr;
	    for (int i = 0; i < nums.size(); i++) {
	        arr.push_back({nums[i], i});
	    }
	    sort(arr.begin(), arr.end());
	    
	    int ans = 0;
	    for (int i = 0; i < nums.size(); i++) {
	        if (arr[i].second == i) continue;
	        else {
	            ans++;
	            swap(arr[i], arr[arr[i].second]);
	            i--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends