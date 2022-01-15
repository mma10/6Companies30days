// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void extractArr(string s,vector<int> &arr){
        string temp = "";
        int i = 0, n = s.size();
        for(int j = 0; j < 4; j++){
            while(i < n && s[i] != '#')
                temp.push_back(s[i++]);
            arr.push_back(stoi(temp));
            temp = "";
            i++;
        }
    }
    
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int quadSum) {
        // Your code goes here
        unordered_map <int,int> freq;
        unordered_set <string> quadSet;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        
         int t = 100;
        vector<vector<int>> quad;
        int i = 0, j = 1;
        for(i = 0; i < n; i++){
            if(i != 0 && arr[i-1] == arr[i]){
                continue;
            }
            for(j = i + 1; j < n; j++){
                if(j != i + 1 && arr[j-1] == arr[j]){
                    continue;
                }
                int left = j + 1, rt = n - 1;
                int search = quadSum - (arr[i] + arr[j]);
                bool preLeft = true;
                
                while(left < rt){
                    int curSum = arr[left] + arr[rt];
                    if(curSum == search){
                        quad.push_back({arr[i], arr[j], arr[left], arr[rt]});
                        left++;
                        while((left < rt) && (left == j + 1 || arr[left] == arr[left - 1]))
                            left++;
                    }
                    else if(curSum < search){
                        left++;
                        while((left < rt) && (left == j + 1 || arr[left] == arr[left - 1]))
                            left++;
                    }
                    else{
                        rt--;
                      while((left < rt) && (rt == n - 1 || arr[rt] == arr[rt + 1]))
                            rt--;
                    }
                }
            }
        }
        
        return quad;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends