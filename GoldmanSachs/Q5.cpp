// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector <ull> ugly(1,1);
	    int index2 = 0, index3 = 0, index5 = 0;
	    for(int i = 0; i < n - 1; i++){
	        ull nextUgly = min(2 * ugly[index2],min(3 * ugly[index3],5 * ugly[index5]));
	        if(2 * ugly[index2] == nextUgly)
	            index2++;
	        if(3 * ugly[index3] == nextUgly)
	            index3++;
	        if(5 * ugly[index5] == nextUgly)
	            index5++;
	            
	        ugly.push_back(nextUgly);
	    }
	    
	    return ugly[n - 1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends