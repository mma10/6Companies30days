// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    int kvowelwords(int n, int k) {
        vector<vector<long long>> dp(n+1, vector<long long>(k+1,0));
        int mod = 1000000007;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= k; j++){
                if(j > i)
                    dp[i][j] = 0;
                else if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(j == 0){
                    dp[i][j] = 0;
                    for(int z = 0; z <= k && z <= i-1; z++)
                        dp[i][j] = (dp[i][j] + dp[i-1][z] + mod) % mod;
                    dp[i][j] = (dp[i][j] * 21) % mod;
                }
                else
                    dp[i][j] = (dp[i-1][j-1] * 5 + mod) % mod;
            }
        long long ans = 0;
        for(int j = 0; j <= k; j++)
            ans = (ans + dp[n][j]) % mod;
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends