// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        int l1[2] = { min(L1[0],R1[0]), max(L1[1],R1[1]) };
        int r1[2] = { max(L1[0],R1[0]), min(L1[1],R1[1]) };
        int l2[2] = { min(L2[0],R2[0]), max(L2[1],R2[1]) };
        int r2[2] = { max(L2[0],R2[0]), min(L2[1],R2[1]) };
        
        if((l2[0] <= r1[0] && r2[0] >= l1[0]) && (l2[1] >= r1[1] && r2[1] <= l1[1]))
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends