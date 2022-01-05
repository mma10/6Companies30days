// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        int n = s.size();
        stack <string> st;
        
        for(int i = 0; i < n; i++){
            if(s[i] != ']')
                st.push(string(1,s[i]));
            else{
                string innerStr = "";
                vector <string> strArr;
                while(!st.empty() && st.top() != "["){
                    strArr.push_back(st.top());
                    st.pop();
                }
                reverse(strArr.begin(),strArr.end());
                for(string str : strArr)
                    innerStr.append(str);
                
                if(!st.empty())
                    st.pop();
                string numStr = "";
                int num;
                if(st.empty() || !isdigit(st.top()[0]))
                    numStr = "1";
                while(!st.empty() && isdigit(st.top()[0])){
                    numStr.append(st.top());
                    st.pop();
                }
                reverse(numStr.begin(),numStr.end());
                num = stoi(numStr);
                
                // cout << num << endl;
                for(int k = 0; k < num; k++){
                    st.push(innerStr);
                    // cout << innerStr << endl;
                }
            }
        }
        
        string decode = "";
        vector <string> strArr;
        while(!st.empty() && st.top() != "["){
            strArr.push_back(st.top());
            st.pop();
        }
        reverse(strArr.begin(),strArr.end());
        for(string str : strArr)
            decode.append(str);
        
        return decode;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends