// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        // vector<long long> waysClimb(m + 1,0);
        // waysClimb[0] = 1, waysClimb[1] = 1;
        // for(int i = 2; i <= m; i++)
        //     waysClimb[i] = waysClimb[i - 1] + waysClimb[i - 2];
        // return waysClimb[m];
        
        if(m % 2 == 0)
            return m / 2 + 1;
        else
            return (m - 1) / 2 + 1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends