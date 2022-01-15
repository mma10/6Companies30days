// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool isValid(vector<vector<int>> &grid,int row,int col){
        int rows = grid.size(), cols = grid[0].size();
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return false;
        return true;
    }
    
    int dfs(vector<vector<int>> &grid,int srcRow,int srcCol,vector<vector<bool>> &visit){
        visit[srcRow][srcCol] = true;
        int area = 1;
        
        vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1}, dj = {0, 1, 1, 1, 0, -1, -1, -1};
        for(int k = 0; k < 8; k++){
            int neiRow = srcRow + di[k], neiCol = srcCol + dj[k];
            if(isValid(grid,neiRow,neiCol) && !visit[neiRow][neiCol] && grid[neiRow][neiCol] == 1)
                area += dfs(grid,neiRow,neiCol,visit);
        }
        return area;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visit(m,vector<bool> (n,false));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!visit[i][j] && grid[i][j] == 1){
                    int curArea = dfs(grid,i,j,visit);
                    maxArea = max(maxArea,curArea);
                }
        return maxArea;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends