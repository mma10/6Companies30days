// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string toBinary(int num){
    string binary = "";
    while(num > 0){
        char ch = num % 2 + '0';
        binary.push_back(ch);
        num /= 2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}

vector<string> generate(int n)
{
	// Your code here
	vector<string> binary(n);
	for(int i = 0; i < n; i++){
	    int num = i + 1;
	    binary[i] = toBinary(num);
	}
	return binary;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends