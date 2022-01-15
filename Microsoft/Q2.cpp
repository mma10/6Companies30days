// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCyclic(vector<vector<int>> &graph,int n){
        vector<int> inDegree(n,0);
        int visit = 0;
        queue <int> nodes;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (int)graph[i].size(); j++){
                int u = i, v = graph[i][j];
                inDegree[v]++;
            }
            
        for(int i = 0; i < n; i++)
            if(inDegree[i] == 0){
                nodes.push(i);
                visit++;
            }
        while(!nodes.empty()){
            int u = nodes.front();
            nodes.pop();
            for(int v : graph[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    nodes.push(v);
                    visit++;
                }
            }
        }
        
        return visit != n;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> graph(N);
	    for(pair<int,int> &p : prerequisites)
	        graph[p.second].push_back(p.first);
	    
	    return !isCyclic(graph,N);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends