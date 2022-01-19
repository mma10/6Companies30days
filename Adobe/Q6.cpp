// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> findPar(int n,vector<vector<string>> &dp){
        if(n == 0)
            return {""};
        if(dp[n].size() != 0)
            return dp[n];
        set <string> par;
        for(int i = 0; i < n; i++){
            vector<string> s1 = findPar(i,dp);
            int j = n - 1 - i;
            vector<string> s2 = findPar(j,dp);
            
            for(string s_1 : s1){
                string cur = "(";
                cur.append(s_1);
                cur.append(")");
                for(string s_2 : s2){
                    string newCur = cur;
                    newCur.append(s_2);
                    par.insert(newCur);
                }
            }
        }
        vector<string> parStr;
        for(auto it : par)
            parStr.push_back(it);
        return dp[n] = parStr;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<vector<string>> dp(n+1);
        vector<string> par = findPar(n,dp);
        return par;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends