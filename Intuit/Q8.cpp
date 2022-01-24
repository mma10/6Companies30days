class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 0; i < n; i++){
            int x = points[i][0], y = points[i][1];
            unordered_map <int,int> dist;
            for(int j = 0; j < n; j++){
                if(i != j){
                    int nx = points[j][0], ny = points[j][1];
                    int curDist = pow(x-nx,2) + pow(y-ny,2);
                    ans += 2 * dist[curDist];
                    dist[curDist]++;
                }
            }
        }
        return ans;
    }
};