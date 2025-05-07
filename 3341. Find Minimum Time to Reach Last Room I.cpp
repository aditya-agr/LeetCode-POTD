class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = 0;
        while(!pq.empty()){
            vector<int> x = pq.top();
            pq.pop();
            int time = x[0];
            int i = x[1];
            int j = x[2];
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m){
                    int nt = max(time, moveTime[i_][j_]) + 1;
                    if(res[i_][j_] > nt){
                        res[i_][j_] = nt;
                        pq.push({nt, i_, j_});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};