// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.size(), mod = 1000000007;
		    vector <int> decode(n + 1,0);
		    decode[n] = 1;
		    if(str[n - 1] != '0')
		        decode[n - 1] = 1;
		    
		    for(int i = n - 2; i >= 0; i--){
		        if(str[i] == '0')
		            continue;
		        decode[i] = (decode[i] + decode[i + 1]) % mod;
		        string numStr = str.substr(i,2);
		        int num = stoi(numStr);
		        if(num >= 1 && num <= 26)
		            decode[i] = (decode[i] + decode[i + 2]) % mod;
		    }
		    
		    return decode[0];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends