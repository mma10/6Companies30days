class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, m = prerequisites.size();
        vector<int> indeg(n,0);
        vector<vector<int>> graph(n);
        for(vector<int> pre: prerequisites){
            indeg[pre[0]]++;
            graph[pre[1]].push_back(pre[0]);
        }
        queue<int> nodes;
        vector<int> order;
        int count = 0;
        for(int i = 0; i < n; i++)
            if(indeg[i] == 0)
                nodes.push(i);
        while(!nodes.empty()){
            int u = nodes.front();
            order.push_back(u);
            nodes.pop();
            count++;
            for(int v: graph[u]){
                indeg[v]--;
                if(indeg[v] == 0)
                    nodes.push(v);
            }
        }
        if(count == n)
            return order;
        return {};
    }
};