class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minSize = INT_MAX;
        int i = 0, j = 0, sum = 0;
        bool oneFound = false;
        
        while(j < n){
            sum += nums[j];           
            while(i <= j && sum >= target){
                minSize = min(minSize,j - i + 1);               
                sum -= nums[i++];        
            }       
            j++;
        }        
        return minSize == INT_MAX ? 0 : minSize;
    }
};