// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

typedef pair<int,int> pd;
class Solution
{
    public:
    void swap(string &str,int i,int j){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    
    void maxNum(string &str,string &maxStr,int k){
        if(str > maxStr)
            maxStr = str;
        if(k == 0)
            return;
            
       int n = str.size();
       for(int i = 0; i < n; i++){
            char maxChar = str[i];
            for(int j = i+1; j < n; j++)
                if(str[j] > maxChar)
                    maxChar = str[j];
            for(int j = i+1; j < n; j++){
                if(str[j] == maxChar && str[i] < str[j]){
                    swap(str,i,j);
                    maxNum(str,maxStr,k-1);
                    swap(str,i,j);
                }
            }
       }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string &str, int k)
    {
       // code here.
       string maxStr = str;
       maxNum(str,maxStr,k);
       return maxStr;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends