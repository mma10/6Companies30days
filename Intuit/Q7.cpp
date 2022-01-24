class Solution {
public:
    int findNumDays(vector <int> &weights,int cap){
        int size = weights.size(), reqDays = 0, hold = 0;
        if(size == 0)
            return 0;
        
        for(int i = 0; i < size; i++){
            hold += weights[i];
            if(hold > cap){
                reqDays++;
                hold = weights[i];
            }
        }
        return ++reqDays;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {        
        int minCap = *max_element(weights.begin(),weights.end()), maxCap = 0, size = weights.size();
        for(int i = 0; i < size; i++)
            maxCap += weights[i];
        
        while(minCap < maxCap){
            int curCap = (minCap + maxCap) / 2;
            int reqDays = findNumDays(weights,curCap);            
            if(reqDays <= days)
                maxCap = curCap;
            else
                minCap = curCap + 1;
        }
        
        return minCap;
    }
};