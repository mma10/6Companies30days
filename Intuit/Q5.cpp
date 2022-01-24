class Solution {
public:
    int minWindows(vector<int> &nums,int maxSum){
        int n = nums.size(), windows = 0, sum = 0;      
        for(int num : nums){
            sum += num;
            if(sum > maxSum){
                windows++;
                sum = num;
            }
        }
        return ++windows;
    }
        
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(), sum = 0;
        for(int num : nums)
            sum += num;
        int l = *max_element(nums.begin(),nums.end()), r = sum;
        while(l < r){
            int mid = (l + r) / 2;
            int windows = minWindows(nums,mid);
            if(windows <= m)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};