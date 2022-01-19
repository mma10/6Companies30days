// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    void swap(string &s,int i,int j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
  
    string nextPalin(string s) { 
        //complete the function here
        int n = s.size();
        int end = n / 2 - 1;
        bool poss = false;
        int index = -1;
        for(int st = end - 1; !poss && st >= 0; st--){
            if(s[st] < s[st + 1]){
                for(int i = end; i > st; i--){
                    if(s[st] < s[i]){
                        int compSt = n - 1 - st, compi = n - 1 - i;
                        swap(s,st,i);
                        swap(s,compSt,compi);
                        break;
                    }
                }
                poss = true;
                index = st;
            }
        }
        
        if(!poss)
            return "-1";
        int indexInc = index + 1, endInc = end + 1;
        sort(s.begin() + indexInc,s.begin() + endInc);
        string num = s.substr(0,endInc);
        string nextPal = num;
        if(n % 2 == 1)
            nextPal.push_back(s[end + 1]);
        reverse(num.begin(),num.end());
        nextPal.append(num);
        return nextPal;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends