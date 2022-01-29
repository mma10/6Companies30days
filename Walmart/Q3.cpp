class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aRem = 0, bRem = 0;
        for(int i = 1; i < n-1; i++){
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A')
                aRem++;
            else if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B')
                bRem++;
        }
        return aRem > bRem;
    }
};