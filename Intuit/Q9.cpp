class Solution {
public:
    bool isValid(vector<vector<int>> &heights,int i,int j){
        int m = heights.size(), n = heights[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>> &heights,int row,int col,vector<vector<bool>> &visit){       
        visit[row][col] = true;        
        vector<int> di = {-1, 0, 1, 0}, dj = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            int nRow = row + di[k], nCol = col + dj[k];            
            if(isValid(heights,nRow,nCol) && !visit[nRow][nCol] && heights[row][col] <= heights[nRow][nCol]){
                dfs(heights,nRow,nCol,visit);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        for(int i = 0; i < m; i++)
            if(!pac[i][0])
                dfs(heights,i,0,pac);
        for(int j = 0; j < n; j++)
            if(!pac[0][j])
                dfs(heights,0,j,pac);
        
        for(int i = 0; i < m; i++)
            if(!atl[i][n-1])
                dfs(heights,i,n-1,atl);
        for(int j = 0; j < n; j++)
            if(!atl[m-1][j])
                dfs(heights,m-1,j,atl);
        
        vector<vector<int>> common;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j])
                    common.push_back({i,j});
            }
        return common;
    }
};