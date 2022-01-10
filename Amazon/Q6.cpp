// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector <int> preMax(n,INT_MIN), sufMax(n,INT_MIN);
        int curPreMax = INT_MIN, curSufMax = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i % k == 0)
                curPreMax = INT_MIN;
            curPreMax = max(curPreMax,arr[i]);
            preMax[i] = curPreMax;
            
            int j = n - 1 - i;
            if(j % k == k - 1)
                curSufMax = INT_MIN;
            curSufMax = max(curSufMax,arr[j]);
            sufMax[j] = curSufMax;
        }
        
        vector <int> maxArr;
        for(int i = 0; k + i - 1 < n; i++){
            int j = k + i - 1;
            maxArr.push_back(max(sufMax[i],preMax[j]));
        }
        
        return maxArr;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends