class Solution {
public:
    int getMoneyAmount(int n) {       
        vector<vector<int>> money(n+1,vector<int>(n+1,INT_MAX));
        for(int i = n; i >= 1; i--)
            for(int j = i; j <= n; j++){
                if(i == j)
                    money[i][j] = 0;
                else{
                    for(int k = i; k <= j; k++){
                        int curMoney = k;
                        int topMoney = 0, botMoney = 0;
                        if(k+1 <= j)
                            topMoney = money[k+1][j];
                        if(k-1 >= i)
                            botMoney = money[i][k-1];
                        curMoney += max(topMoney,botMoney);  
                        money[i][j] = min(money[i][j],curMoney);
                    }
                }
            }
        return money[1][n];
    }
};