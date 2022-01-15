// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void findPossWords(int a[],int i,int n,string &curWord,vector<string> &possWords,vector<string> &numpad){
        if(i == n){
            possWords.push_back(curWord);
            return;
        }
        
        string charStr = numpad[a[i]];
        for(int j = 0; j < (int)charStr.size(); j++){
            curWord.push_back(charStr[j]);
            findPossWords(a,i + 1,n,curWord,possWords,numpad);
            curWord.pop_back();
        }
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> numpad(10);
        char c = 'a';
        for(int i = 2; i <= 9; i++){
            for(int j = 0; j < 3; j++){
                numpad[i].push_back(c);
                c++;
            }
            if(i == 7 || i == 9){
                numpad[i].push_back(c);
                c++;
            }
        }
        
        vector<string> possWords;
        string curWord = "";
        findPossWords(a,0,N,curWord,possWords,numpad);
        return possWords;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends