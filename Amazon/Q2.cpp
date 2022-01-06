class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        bool isInc = true;
        int i = 0, j = 1, maxLen = 0;
        while(j < n){
            if(isInc){
                if(arr[j] < arr[j - 1]){
                    isInc = false;
                    if(i >= j - 1){
                        i = j;
                        isInc = true;
                    }                        
                }
                else if(arr[j] == arr[j - 1])
                    i = j;                         
            }
            else{
                if(arr[j] > arr[j - 1]){
                    i = j - 1;
                    isInc = true;
                }
                else if(arr[j] == arr[j - 1]){
                    i = j;
                    isInc = true;
                }               
            }
            if(j - i + 1 >= 3 && !isInc)
                maxLen = max(maxLen,j - i + 1);
            j++;
        }
        return maxLen;
    }
};