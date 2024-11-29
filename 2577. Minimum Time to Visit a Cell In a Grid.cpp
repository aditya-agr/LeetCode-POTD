#define P pair<int, pair<int,int>> 
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1)
            return -1;
        vector<vector<int>> res(n, vector<int>(m,INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0,0}});
        res[0][0] = 0;

        while(!pq.empty()){
            P tp = pq.top();
            pq.pop();
            int d = tp.first;
            int i = tp.second.first;
            int j = tp.second.second;
            if(visited[i][j])
                continue;
            visited[i][j] = 1;
            if(i==n-1 && j==m-1)
                return res[i][j];
            for(auto dir : dirs){
                int ni = i+dir[0];
                int nj = j+dir[1];
                if(ni<0 || ni>=n || nj<0 || nj>=m)
                    continue;
                if(d>=grid[ni][nj]){
                    res[ni][nj] = d+1;
                    pq.push({d+1, {ni, nj}});
                }
                else if((grid[ni][nj]-d)%2 == 1){
                    res[ni][nj] = grid[ni][nj];
                    pq.push({grid[ni][nj], {ni, nj}});
                }
                else{
                    res[ni][nj] = grid[ni][nj]+1;
                    pq.push({grid[ni][nj]+1, {ni, nj}});
                }
            }
        }
        return res[n-1][m-1];
    }
};