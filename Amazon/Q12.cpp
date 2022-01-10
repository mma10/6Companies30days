// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        long long num = n;
        string col = "";
        while(num > 0){
            int digit = num % 26;
            if(digit == 0)
                digit = 26;
            char c = 'A' + digit - 1;
            col.push_back(c);
            num = (num - 1) / 26;
        }
        reverse(col.begin(),col.end());
        return col;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends