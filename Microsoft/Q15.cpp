// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(unordered_map <char,vector<char>> &graph,char src,vector<bool> &visit,stack <char> &st){
        visit[src - 'a'] = true;
        for(char nei : graph[src]){
            if(!visit[nei - 'a'])
                dfs(graph,nei,visit,st);
        }
        st.push(src);
    }
    
    string topoSort(unordered_map <char,vector<char>> &graph,int k){
        vector<bool> visit(k,false);
        stack <char> st;
        for(int i = 0; i < k; i++)
            if(!visit[i])
                dfs(graph,'a' + i,visit,st);
        for(int i = 0; i < k; i++)
            if(!visit[i])
                st.push('a' + i);
        string str = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            str.push_back(c);
        }
        return str;
    }
    
    void findDistChar(string s1,string s2,char &c1,char &c2){
        int size = min((int)s1.size(),(int)s2.size());
        for(int i = 0; i < size; i++)
            if(s1[i] != s2[i]){
                c1 = s1[i], c2 = s2[i];
                break;
            }
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map <char,vector<char>> graph;
        string preStr = dict[0], curStr;
        for(int i = 1; i < N; i++){
            curStr = dict[i];
            char cLess = '!', cGrt = '!';
            findDistChar(preStr,curStr,cLess,cGrt);
            if(cLess != '!')
                graph[cLess].push_back(cGrt);
            preStr = curStr;
        }
        return topoSort(graph,K);
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends