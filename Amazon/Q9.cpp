// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int n = mat.size();
        for(int i = 0; i < n; i++){
            set <int> nums;
            for(int j = 0; j < n; j++){
                if(mat[i][j] != 0){
                    if(nums.count(mat[i][j]) == 1)
                        return false;
                    nums.insert(mat[i][j]);
                }
            }
        }
        
        for(int j = 0; j < n; j++){
            set <int> nums;
            for(int i = 0; i < n; i++){
                if(mat[i][j] != 0){
                    if(nums.count(mat[i][j]) == 1)
                        return false;
                    nums.insert(mat[i][j]);
                }
            }
        }
        
        for(int r1 = 0; r1 < n; r1 += 3)
            for(int c1 = 0; c1 < n; c1 += 3){
                set <int> nums;
                for(int i = r1; i < r1 + 3; i++)
                    for(int j = c1; j < c1 + 3; j++)
                        if(mat[i][j] != 0){
                            if(nums.count(mat[i][j]) == 1)
                                return false;
                            nums.insert(mat[i][j]);
                        }
            }
            
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends