#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isGrt(string &s1,string &s2){
    int m = s1.size(), n = s2.size();
    if(m != n)
        return m > n;
    for(int i = 0; i < m; i++){
        if(s1[i] != s2[i])
            return s1[i] > s2[i];
    }
    return false;
}

string getLatestVersion(string &s1,string &s2){
    int m = s1.size(), n = s2.size();
    int i = 0, j = 0;
    while(i < m && j < n){
        string v1 = "", v2 = "";
        while(i < m && s1[i] != '.')
            v1.push_back(s1[i++]);
        i++;
        while(j < n && s2[j] != '.')
            v2.push_back(s2[j++]);
        j++;
        
        if(isGrt(v1,v2))
            return s1;
        else if(v1 != v2)
            return s2;
    }
    
    if(i >= m)
        return s2;
    else
        return s1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        cout << getLatestVersion(s1,s2) << endl;
    }   
	return 0;
}
