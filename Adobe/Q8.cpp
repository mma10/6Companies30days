// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool isGreater(string num1,string num2){
        int n = num1.size(), m = num2.size();
        if(n != m)
            return n > m;
        return num1 > num2;
    }
    
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n = s.size();
        int i = 0;
        while(s[i] == ' ')
            i++;        
        
        bool pos = true;
        if(s[i] == '+' || s[i] == '-'){
            pos = s[i++] == '+' ? true : false;            
        }    
        
        while(s[i] == '0')
            i++;
        
        string digits = "";
        while(isdigit(s[i])){
            digits.push_back(s[i++]);
        }
        if(i < n)
            return -1;
               
        string minInt = "2147483648", maxInt = "2147483647";         
        if(pos && isGreater(digits,maxInt))
            digits = maxInt;
        else if(!pos && isGreater(digits,minInt))
            digits = minInt;
        
        int num = 0;
        int size = digits.size();
        for(int i = 0; i < size; i++)
            num = pos ? num * 10 + (digits[i] - '0') : num * 10 - (digits[i] - '0');
        
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends