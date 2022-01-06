// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

typedef pair<int,int> pd;

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<vector<pd>> profit(n + 1,vector <pd> (k + 2,{ 0 , 0 }));
       
        for(int i = n - 1; i >= 0; i--){
            for(int j = k; j >= 0; j--){
                int profit1, profit2;
                if(j > 0){
                    profit1 = profit[i + 1][j].first;
                    profit2 = a[i] + profit[i + 1][j + 1].second;
                    profit[i][j].first = max(profit1,profit2);
                }
                profit1 = profit[i + 1][j].second;
                profit2 = -a[i] + profit[i + 1][j].first;
                profit[i][j].second = max(profit1,profit2);
            }
        }
        
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= k + 1; j++)
        //         cout << "(" << profit[i][j].first << "," << profit[i][j].second << ")" << " ";
        //     cout << endl;
        // }
        
        int maxProfit = 0;
        for(int j = 0; j <= k; j++){
            maxProfit = max(maxProfit,profit[0][j].second);
            // cout << profit[0][j].second << endl;
        }
            
        return maxProfit;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends