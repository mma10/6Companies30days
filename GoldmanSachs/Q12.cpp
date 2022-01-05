// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        
        // (n-1+1)^2 + (n-2+1)^2 + ... + (n-n+1)^2 = sum(n^2);
        
        return N * (N + 1) * (2 * N + 1) / 6;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends