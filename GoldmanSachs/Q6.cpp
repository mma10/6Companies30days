class Solution {
public:
    bool canDivide(string str,string divisor){
        int m = str.size(), n = divisor.size();
        if(m % n != 0)
            return false;
        
        for(int i = 0; i < m; i++)
            if(str[i] != divisor[i % n])
                return false;            
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int len = gcd(m,n);
        string comStr = str1.substr(0,len);
        bool divStr1 = canDivide(str1,comStr);
        bool divStr2 = canDivide(str2,comStr);
        
        if(divStr1 && divStr2)
            return comStr;
        return "";
    }
};