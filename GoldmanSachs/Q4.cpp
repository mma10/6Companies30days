// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  int n = src.size();
  char preChar = src[0], count = 1;
  string encoded = "";
  
  for(int i = 1; i < n; i++){
    if(src[i] == src[i-1])
        count++;
    else{
        encoded.push_back(preChar);
        encoded.append(to_string(count));
        preChar = src[i];
        count = 1;
    }    
  }
  encoded.push_back(preChar);
  encoded.append(to_string(count));
  
  return encoded;
}     
 
