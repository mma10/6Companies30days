class Solution {
public:
    bool isGrt(string s1,string s2){
        int m = s1.size(), n = s2.size();
        if(m != n)
            return m > n;
        for(int i = 0; i < m; i++){
            if(s1[i] > s2[i])
                return true;
            else if(s1[i] < s2[i])
                return false;
        }
        return false;
    }
    
    class comp{
        public:
           bool operator()(string s1,string s2){
                int m = s1.size(), n = s2.size();
                if(m != n)
                    return m > n;
                for(int i = 0; i < m; i++){
                    if(s1[i] > s2[i])
                        return true;
                    else if(s1[i] < s2[i])
                        return false;
                }
                return false;
           } 
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string,vector<string>,comp> kLarge;
        
        for(int i = 0; i < k; i++)
            kLarge.push(nums[i]);
        for(int i = k; i < n; i++){
            if(isGrt(nums[i],kLarge.top())){
                kLarge.pop();
                kLarge.push(nums[i]);
            }
        }
        return kLarge.top();
    }
};