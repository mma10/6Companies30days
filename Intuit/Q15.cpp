class Solution {
public:
    int findTime(vector<int> &piles,int speed){
        int t = 0;
        for(int p : piles)
            t += ceil(1.0 * p / speed);
        return t;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // long long sum = 0;
        // for(int p : piles)
        //     sum += p;
        int l = 1, r = *max_element(piles.begin(),piles.end());
        while(l < r){
            int mid = (l + r) / 2;
            int t = findTime(piles,mid);
            if(t <= h)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};