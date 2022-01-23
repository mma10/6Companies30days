// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


bool all9(int n){
    while(n > 0){
        if(n % 10 != 9)
            return false;
        n /= 10;
    }
    return true;
}

int getNextDigits(const string &str,int index,int m){
    int n = str.size(), num = 0;
    for(int i = index; i < index + m; i++){
        num = num*10 + (str[i] - '0');
    }
    return num;
}

/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    int n = str.size(), ans = -1;
    for(int dig = 1; dig <= 6; dig++){
        int digits = dig;
        int i = 0, preNum = -1;
        bool sat = true, dif2 = false;
        while(i < n){
            if(digits > n - i){
                sat = false;
                break;
            }
            int num = getNextDigits(str,i,digits);
            if(preNum != -1){
                if(num - preNum != 1 && num - preNum != 2){
                    sat = false;
                    break;
                }
                if(!dif2){
                    if(num - preNum == 2){
                        dif2 = true;
                        ans = num - 1;
                    }
                }
                else{
                    if(num - preNum == 2){
                        sat = false;
                        break;
                    }
                }
            }
            preNum = num;
            i += digits;
            if((num != 0 && all9(num)) || (all9(num / 10) && num % 10 == 8 && i < n && str[i] == '1'))
                digits++;
            // cout << num << endl;
        }
        
        if(sat && dif2){
            // cout << "digits are " << dig << endl;
            return ans;
        }
    }
    
    return -1;
}