// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],int src,int c,int d,vector<bool> &visit){
	    visit[src] = true;
	    for(int nei : adj[src]){
	        if(src == c && nei == d)
	            continue;
	        if(!visit[src])
	            dfs(adj,nei,c,d,visit);
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visit(V,false);
        dfs(adj,c,c,d,visit);
        return visit[d] ? 0 : 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends