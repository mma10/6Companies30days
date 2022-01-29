// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int n){
        // code here
        // int k = 0, sum = 0;
        // while(sum < n){
        //     k++;
        //     sum += k;
        // }
        // if(sum > n)
        //     return k-1;
        // return k;
        
        int k = (-1 + sqrt(1 + 8 * n)) / 2;
        return k;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends