// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        int n = s.size();
        string sent = "";
        for(int i = 0; i < n;){
            string word = "";
            word.push_back(tolower(s[i++]));
            while(i < n && !isupper(s[i]))
                word.push_back(s[i++]);
            if(i != n)
                word.push_back(' ');
            sent.append(word);
        }
        return sent;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends