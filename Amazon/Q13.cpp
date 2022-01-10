class Solution {
public:
    class orange{
        public:
            int row;
            int col;
            int type;
            orange(int r,int c,int t){
                row = r;
                col = c;
                type = t;
            }
    };
    
    bool isValid(vector<vector<int>> &grid,int i,int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    
    void getRotOranges(queue<orange> &rotOranges,vector<vector<int>> &grid,vector<vector<bool>> &visit,int &freshOranges){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    freshOranges++;
                else if(grid[i][j] == 2){
                    rotOranges.push(orange(i,j,2));
                    visit[i][j] = true;
                }
            }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m,vector<bool> (n,false));
        queue <orange> rotOranges;
        int freshOranges = 0;
        getRotOranges(rotOranges,grid,visit,freshOranges);
        
        vector<int> di = {-1, 0, 1, 0,}, dj = {0, 1, 0, - 1};
        
        int minTime = 0;
        while(!rotOranges.empty()){
            int size = rotOranges.size();
            while(size--){
                orange curOrange = rotOranges.front();
                rotOranges.pop();
                int row = curOrange.row, col = curOrange.col;
                
                for(int k = 0; k < 4; k++){
                    int nRow = row + di[k], nCol = col + dj[k];
                    if(isValid(grid,nRow,nCol) && !visit[nRow][nCol] && grid[nRow][nCol] == 1){
                        rotOranges.push(orange(nRow,nCol,2));
                        freshOranges--;
                        visit[nRow][nCol] = true;
                    }
                }
            }
            
            minTime++;
        }
        
        if(freshOranges > 0)
            return -1;
        else
            return max(minTime - 1,0);
    }
};