// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map <char,list <char> :: iterator> pointers;
		    vector <int> freq(26,0);
		    list <char> nonRep;
		    string firstNonRep = "";
		    for(char c : A){
		        freq[c - 'a']++;
		        if(freq[c - 'a'] == 1){
		            nonRep.push_back(c);
		            pointers[c] = --nonRep.end();
		        }
		        else if(freq[c - 'a'] == 2){
                    nonRep.erase(pointers[c]);
                    pointers.erase(c);
		        }
		        
		        if(!nonRep.empty())
                    firstNonRep.push_back(*nonRep.begin());
                else
                    firstNonRep.push_back('#');
		    }
			return firstNonRep;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends