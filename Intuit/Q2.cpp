// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isValid(vector<vector<char>> &board,int i,int j){
        int m = board.size(), n = board[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }

    void dfs(vector<vector<char>> &board,int i,int j,string &word,int index,bool &exists,unordered_set<int> &anc){
        int n = word.size(), col = board[0].size();
        if(index == n){
            exists = true;
            return;
        }
        anc.insert(i*col + j%col);
        
        vector<int> di = {-1, 0, 1, 0}, dj = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            int nRow = i + di[k], nCol = j + dj[k];
            if(isValid(board,nRow,nCol) && word[index] == board[nRow][nCol] && anc.count(nRow*col + nCol%col) == 0)
                dfs(board,nRow,nCol,word,index+1,exists,anc);
        }
        anc.erase(i*col + j%col);
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        if(word.size() == 0)
            return false;
        int m = board.size(), n = board[0].size();
        bool exists = false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    unordered_set<int> anc;
                    dfs(board,i,j,word,1,exists,anc);
                    if(exists)
                        return true;
                }
            }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends