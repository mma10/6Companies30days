class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,int src,vector<bool> &visit){
        int n = isConnected.size();
        visit[src] = true;
        for(int i = 0; i < n; i++){
            if(isConnected[src][i] == 1 && !visit[i])
                dfs(isConnected,i,visit);            
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<bool> visit(n,false);
        for(int i = 0; i < n; i++)
            if(!visit[i]){
                dfs(isConnected,i,visit);
                provinces++;
            }
        return provinces;        
    }
};