// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map <int,int> rems;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int rem = ((nums[i] % k) + k) % k;
            int search = (k - rem) % k;
            if(rems[search] > 0){
                rems[rem]--;
                rems[search]--;
            }
            rems[rem]++;
        }
        for(auto it : rems)
            if(it.second > 0)
                return false;
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends