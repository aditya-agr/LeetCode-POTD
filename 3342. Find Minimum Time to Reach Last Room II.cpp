class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> res(n, vector<int>(m,INT_MAX));
        res[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0,0});

        while(!pq.empty()){
            vector<int> cur = pq.top();
            int time = cur[0];
            int i = cur[1];
            int j = cur[2];
            int flag = cur[3];
            pq.pop();
            for(vector<int> &d : dir){
                int i_ = i + d[0];
                int j_ = j + d[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m){
                    int ntime = max(time, moveTime[i_][j_]);
                    ntime += (flag == 0) ? 1 : 2;
                    if(ntime < res[i_][j_]){
                        res[i_][j_] = ntime;
                        pq.push({ntime, i_, j_, flag^1});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};