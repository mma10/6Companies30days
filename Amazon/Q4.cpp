// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixMultOrder(vector<vector<int>> &minMult,int p[],int i,int j,int &curMatrix){
        if(j - i == 1)
            return string(1,'A'+curMatrix++);
            
        for(int k = i + 1; k < j; k++){
            int curMult = minMult[i][k] + minMult[k][j] + p[i]*p[k]*p[j];
            if(curMult == minMult[i][j]){
                string str1 = matrixMultOrder(minMult,p,i,k,curMatrix);
                string str2 = matrixMultOrder(minMult,p,k,j,curMatrix);
                string str = "(" + str1 + str2 + ")";
                return str;
            }
        }
        
        return "";
    }

    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>> minMult(n,vector<int> (n,INT_MAX));
        for(int i = n - 1; i >= 0; i--)
            for(int j = i + 1; j < n; j++){
                if(j - i == 1)
                    minMult[i][j] = 0;
                else{
                    for(int k = i + 1; k < j; k++){
                        minMult[i][j] = min(minMult[i][j],minMult[i][k] + minMult[k][j] + p[i]*p[k]*p[j]);
                    }
                }
            }
        
        int curMatrix = 0;
        string str = matrixMultOrder(minMult,p,0,n - 1,curMatrix);
        return str;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends