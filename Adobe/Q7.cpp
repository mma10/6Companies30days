// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&a,int n)
    {
	    //Write your code 
	    vector<vector<int>> dp(n,vector<int> (n,0));
	    vector<int> preSum(n+1,0);
	    for(int i = 1; i <= n; i++)
	        preSum[i] = a[i - 1] + preSum[i - 1];
	    for(int i = n - 1; i >= 0; i--)
	        for(int j = i; j < n; j++){
	            if(i == j)
	                dp[i][j] = a[i];
	            else{
	                int curSum = preSum[j + 1] - preSum[i];
	                int minNext = min(dp[i + 1][j],dp[i][j - 1]);
	                dp[i][j] = curSum - minNext;
	            }
	        }
	    return dp[0][n - 1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends