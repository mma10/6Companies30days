// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.size(), i = 0;
        string s;
        set <int> digits;
        for(int i = 1; i <= 9; i++)
            digits.insert(i);
            
        if(S[i] == 'I'){
            s.push_back('1');
            digits.erase(1);
        }
        
        int dCount = 0;
        while(i < n){
            if(S[i] == 'I'){
                if(i + 1 >= n || S[i + 1] != 'D'){
                    s.push_back('0' + *digits.begin());
                    if(!digits.empty())
                        digits.erase(digits.begin());
                }
                dCount = 0;  
            }
            else{
                dCount++;
                if(i + 1 >= n || S[i + 1] != 'D'){
                    string temp = "";
                    for(int j = 0; j < dCount + 1; j++){
                        temp.push_back('0' + *digits.begin());
                        if(!digits.empty())
                            digits.erase(digits.begin());
                    }
                    reverse(temp.begin(),temp.end());
                    s.append(temp);
                }
            }
            i++;
        }
        
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends