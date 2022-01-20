// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.    
    public:

    // WITH STACK O(n) space
    // vector<int> leaders(int a[], int n){
    //     // Code here
    //     stack <int> st;
    //     vector<bool> isLead(n,true);
        
    //     for(int i = 0; i < n; i++){
    //         while(!st.empty() && a[i] > a[st.top()]){
    //             isLead[st.top()] = false;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     vector<int> leads;
    //     for(int i = 0; i < n; i++)
    //         if(isLead[i])
    //             leads.push_back(a[i]);
    //     return leads;
    // }

    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> leads = {a[n - 1]};;
        int rtMax = a[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            if(a[i] >= rtMax)
                leads.push_back(a[i]);
            rtMax = max(rtMax,a[i]);
        }
        reverse(leads.begin(),leads.end());
        return leads;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends