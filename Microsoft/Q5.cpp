// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> span(n,-1);
       stack <int> indexes;
       for(int i = n - 1; i >= 0; i--){
           while(!indexes.empty() && price[i] > price[indexes.top()]){
               int index = indexes.top();
               indexes.pop();
               span[index] = index - i;
           }
           indexes.push(i);
       }
       
       for(int i = 0; i < n; i++)
            if(span[i] == -1)
                span[i] = i + 1;
        return span;    
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends