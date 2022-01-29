// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n == 1)
            return 1;
        int ans = 2;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for(int i = n-1; i >= 0; i--){
            unordered_map <int,int> indexes;
            for(int j = i+1; j < n; j++){
                if(indexes.count(arr[j]) == 0)
                    indexes[arr[j]] = j;
            }
            for(int j = i+1; j < n; j++){
                indexes.erase(arr[j]);
                int ele1 = arr[i], ele2 = arr[j];
                int search = 2*ele2 - ele1;
                if(indexes.count(search) == 1){
                    int k = indexes[search];
                    dp[i][j] = dp[j][k] + 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends