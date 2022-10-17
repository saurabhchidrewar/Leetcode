//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector <int> ans;
		for (int col = 0; col < N-1; col++) {
		    int i = 0, j = col;
		    while (i >= 0 && i < N && j >= 0 && j < N) {
		        ans.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		for (int row = 0; row < N; row++) {
		    int i = row, j = N-1;
		    while (i >= 0 && i < N && j >= 0 && j < N) {
		        ans.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		return ans;
	}

};

/*
0,0
0,1 1,0
0,2 1,1 0,2
*/


//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends