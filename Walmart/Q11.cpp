class Solution {
public:
    typedef pair<long long,long long> pd;  
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {        
        int mod = 1000000007;
        long long maxPerf = 0;
        vector<pd> persons(n);
        for(int i = 0; i < n; i++){
            persons[i].first = efficiency[i];
            persons[i].second = speed[i];
        }
        
        sort(persons.begin(),persons.end(),[&](pd &p1,pd &p2){
            return p1.first >= p2.first;
        });
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long topSum = 0;
        for(int i = 0; i < n; i++){            
            long long curPerf = (topSum + persons[i].second) * persons[i].first;            
            maxPerf = max(maxPerf,curPerf);
            
            pq.push(persons[i].second);
            topSum += persons[i].second;
            if(pq.size() > k-1){
                topSum -= pq.top();
                pq.pop();
            }
        }
        
        return maxPerf % mod;
    }
};