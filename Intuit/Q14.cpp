class Solution {
public:
    bool isValid(vector<vector<int>> &grid,int i,int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    
    void visitLands(vector<vector<int>> &grid,vector<vector<bool>> &visit,queue<int> &nodes){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    visit[i][j] = true;
                    nodes.push(i * n + j % n);
                }
            }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        queue <int> nodes;
        visitLands(grid,visit,nodes);
        if(nodes.size() == 0 || nodes.size() == m*n)
            return -1;
        int dist = 0;
        vector<int> di = {-1, 0, 1, 0}, dj = {0, 1, 0, -1};
        while(!nodes.empty()){
            int size = nodes.size();
            while(size--){
                int cell = nodes.front();
                nodes.pop();
                int row = cell / n, col = cell % n;
                for(int k = 0; k < 4; k++){
                    int nRow = row + di[k], nCol = col + dj[k];
                    if(isValid(grid,nRow,nCol) && !visit[nRow][nCol]){
                        visit[nRow][nCol] = true;
                        nodes.push(nRow * n + nCol % n);
                    }
                }
            }
            dist++;
        }
        return max(0,dist-1);
    }
};