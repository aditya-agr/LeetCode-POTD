#define P pair<int, pair<int,int>>

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0,0}});
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, INT_MAX));
        visited[0][0] = 0;
        while(!pq.empty()){
            P tp = pq.top();
            pq.pop();
            int d = tp.first;
            int i = tp.second.first;
            int j = tp.second.second;
            for(auto dir : dirs){
                int ni = i+dir[0];
                int nj = j+dir[1];
                if(ni>=n || ni<0 || nj>=m || nj<0)
                    continue;
                int wt = grid[ni][nj];
                if(d+wt<visited[ni][nj]){
                    visited[ni][nj] = d+wt;
                    pq.push({d+wt, {ni, nj}});
                }
            }
        }
        return visited[n-1][m-1];
    }
};