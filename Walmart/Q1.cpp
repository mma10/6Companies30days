class Solution {
public:
    typedef pair<int,double> pd;
    typedef pair<double,int> pd1;
       
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int e = edges.size();        
        vector<vector<pd>> graph(n);
        for(int i = 0; i < e; i++){
            int u = edges[i][0], v = edges[i][1];
            double wt = succProb[i];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        priority_queue<pd1> nodes;
        vector<double> prob(n,-1.0);
        vector<bool> visit(n,false);        
        prob[start] = 1.0;       
        nodes.push({prob[start],start});
        
        while(!nodes.empty()){
            pd1 node = nodes.top();
            int vert = node.second;     
            nodes.pop();
            if(!visit[vert]){
                visit[vert] = true;
                for(pd neiNode: graph[vert]){
                    int nei = neiNode.first;
                    double neiWt = neiNode.second;
                    if(prob[vert] * neiWt > prob[nei]){
                        prob[nei] = prob[vert] * neiWt;
                        nodes.push({prob[nei],nei});
                    }
                }
            }
        }        
        return prob[end] != -1.0 ? prob[end] : 0;
    }
};