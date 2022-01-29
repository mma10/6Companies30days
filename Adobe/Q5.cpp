// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1000000007;
    long long numWays(int n,int i,int x,vector<vector<long long>> &dp){
        if(n == 0)
            return 1;
        if(i > n)
            return 0;
        if(dp[n][i] != -1)
            return dp[n][i];
            
        dp[n][i] = 0;
        long long val = n - pow(i,x);
        if(val >= 0)
            dp[n][i] = (dp[n][i] + numWays((int)val,i+1,x,dp)) % mod;
        dp[n][i] = (dp[n][i] + numWays(n,i+1,x,dp)) % mod;
        return dp[n][i];
    }
    
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<long long>> dp(n+1,vector<long long>(n+2,-1));
        return numWays(n,1,x,dp);
        // for(int i = 0; i <= n; i++)
        //     for(int j = n+1; j > 0; j--){
        //         dp[i][j] = 0;
        //         if(i == 0)
        //             dp[i][j] = 1;
        //         else if(j == n+1)
        //             dp[i][j] = 0;
        //         else{
        //             long long val = i - pow(j,x);
        //             if(val >= 0)
        //                 dp[i][j] += dp[val][j+1];
        //             dp[i][j] += dp[i][j+1];
        //         }
        //     }
        // return dp[n][1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends