class Solution {
public:
    void swap(vector<int> &a,int i,int j){
        int t = a[i];
        a[i] = a[j];
        a[j] = t;       
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;        
        for(int i = 0; i < n; i++){
            int ct = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 1)
                    break;
                else
                    ct++;
            }
            arr.push_back(ct);    
            // cout << ct << " "; 
        }
               
        int ans = 0;
        for(int i = 0; i < n; i++){      
            int index = -1, j;            
            for(j = i; j < n; j++){                
                if(arr[j] >= n-1-i){                   
                    index = j;      
                    break;
                }
            }
                
            if(index == -1)
                return -1;  
            for(j = index-1; j >= i; j--)
                swap(arr,j,j+1);            
            ans += abs(i-index);
        }
        return ans;
    }
};