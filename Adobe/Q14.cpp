// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range

typedef pair<int,int> pd;

class Solution{
    public:
    class trio{
        public:
            int num;
            int row;
            int col;
            
            trio(int a,int b,int c){
                num = a, row = b, col = c;
            }
    };
    
    class compH{
        public:
            bool operator()(trio& t1,trio& t2){
                return t1.num > t2.num;
            }
    };
    
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        //code here
        priority_queue<trio,vector<trio>,compH> pq;
        int low = INT_MAX, high = INT_MIN, range = INT_MAX;
        int rangeMin, rangeMax;
        for(int i = 0; i < k; i++){
            pq.push(trio(a[i][0],i,0));
            low = min(low,a[i][0]);
            high = max(high,a[i][0]);
        }
        range = high - low + 1;
        rangeMin = low, rangeMax = high;
        
        while(!pq.empty()){
            int num = pq.top().num, row = pq.top().row, col = pq.top().col;
            pq.pop();
            
            if(col + 1 >= n)
                break;
            pq.push(trio(a[row][col + 1],row,col + 1));
            high = max(high,a[row][col + 1]);
            low = pq.top().num;
            if(high - low + 1 < range){
                range = high - low + 1;
                rangeMin = low, rangeMax = high;
            }
        }
        
        return {rangeMin, rangeMax};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends