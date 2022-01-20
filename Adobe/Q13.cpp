// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int getLIS(vector<int> &a){
        int n = a.size();
        int len = 0;
        vector<int> tail(n,-1);
        
        for(int num : a){
            int l = 0, r = len;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(num > tail[mid])
                    l = mid + 1;
                else
                    r = mid;
            }
            tail[l] = num;
            if(l == len)
                len++;
            // len = l + 1;
            // cout << len << " " << num << endl;
        }
        return len;
    }
  
    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        int ans = 0;
        vector<int> arr;
        unordered_set <int> bSet;
        for(int i = 0; i < m; i++)
            bSet.insert(b[i]);
        for(int i = 0; i < n; i++)
            if(bSet.count(a[i]) == 1)
                arr.push_back(a[i]);
        ans = n - (int)arr.size();
        n = arr.size();
        
        int lis = getLIS(arr);
        // cout << lis << endl;
        ans += (n - lis) + (m - lis);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends