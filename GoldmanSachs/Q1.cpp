// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    void sortString(string &str){
        vector <int> freq(26,0);
        for(char c : str)
            freq[c - 'a']++;
        
        int k = 0;
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                str[k++] = 'a' + i;
                freq[i]--;
            }
        }
    }
  
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector <vector<string>> groups;
        unordered_map <string,int> indexes;
        
        for(string str : string_list){
            string orgStr = str;
            sortString(str);
            int index = -1;
            if(indexes.count(str) == 0){
                groups.push_back({});
                index = groups.size() - 1;
                indexes[str] = index;
            }
            
            index = indexes[str];
            groups[index].push_back(orgStr);
        }
        
        return groups;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends