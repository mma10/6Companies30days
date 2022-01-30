class Solution {
public:
    int divide(int divident, int divisor) {
        if(divident == INT_MIN && divisor == -1)
            return INT_MAX;
        long long divd = labs(divident), divs = labs(divisor), quo = 0;
        int sign = 1;
        sign = divident >= 0 ? sign : sign * -1;
        sign = divisor >= 0 ? sign : sign * -1;
        while(divd - divs >= 0){
            long long temp = divs, curAns = 1;
            while(divd >= temp << 1){
                temp = temp << 1;
                curAns = curAns << 1;
            }
            divd -= temp;
            quo += curAns;
        }
        return quo *= sign;
    }
};