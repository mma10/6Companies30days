// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    // void fillPart(vector<vector<bool>> &partition,int arr[],int n,int i,int dif){
    //     if(i < 0 || i > n)
    //         return;
            
    //     if(partition[i][dif])
    //         return;
        
    //     partition[i][dif] = true;
    //     fillPart(partition,arr,n,i + 1,abs(dif + arr[i]));
    //     fillPart(partition,arr,n,i + 1,abs(dif - arr[i]));
    // }
    
    void subsetSum(vector<vector<bool>> &partition,int arr[],int n,int sum){
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= sum; j++){
                if(j == 0)
                    partition[i][j] = true;
                else if(i == 0)
                    partition[i][j] = false;
                else{
                    int ele = arr[i - 1];
                    if(j - ele >= 0)
                        partition[i][j] = partition[i - 1][j - ele] | partition[i - 1][j];
                    else
                        partition[i][j] = partition[i - 1][j];
                }
            }
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i < n; i++)
	        sum += abs(arr[i]);
	    vector<vector<bool>> partition(n + 1,vector<bool> (sum + 1,false));
	    subsetSum(partition,arr,n,sum);
	    
	    int minDif = INT_MAX;
	    for(int j = 0; j <= sum; j++){
	        if(partition[n][j])
	            minDif = min(minDif,abs(sum - 2 * j));
	    }
	    
	    return minDif;
	    
	   // fillPart(partition,arr,n,0,0);
	   // for(int j = 0; j <= sum; j++)
	   //     if(partition[n][j])
	   //         return j;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends