// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int m = r, n = c, level = 0;
        int minDim = min(m,n);
        vector <int> spiral;
        
        for(level = 0; level <= (minDim - 1) / 2; level++){
            int i,j;
            if(level == (minDim - 1) / 2 && minDim % 2 == 1){
                if(m == minDim){
                    i = level;
                    for(j = level; j <= n - 1 - level; j++)
                        spiral.push_back(matrix[i][j]);
                }
                else{
                    j = level;
                    for(int i = level; i <= m - 1 - level; i++)
                        spiral.push_back(matrix[i][j]);
                }
            }
            else{
                i = level;
                for(j = level; j < n - 1 - level; j++)
                    spiral.push_back(matrix[i][j]);
                
                j = n - 1 - level;
                for(i = level; i < m - 1 - level; i++)
                    spiral.push_back(matrix[i][j]);
                    
                i = m - 1 - level;
                for(j = n - 1 - level; j > level; j--)
                    spiral.push_back(matrix[i][j]);
                    
                j = level;
                for(i = m - 1 - level; i > level; i--)
                    spiral.push_back(matrix[i][j]);
            }    
        }
        
        return spiral;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends