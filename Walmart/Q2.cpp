class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();        
        vector<vector<int>> difPiles(n,vector<int>(n,0));       
        for(int i = n-1; i >= 0; i--)
            for(int j = i; j < n; j++){
                if(i == j)
                    difPiles[i][j] = piles[i];
                else{
                    difPiles[i][j] = max(piles[i] - difPiles[i+1][j],piles[j] - difPiles[i][j-1]); 
                }
            }        
        return difPiles[0][n-1] >= 0;  
    }
};