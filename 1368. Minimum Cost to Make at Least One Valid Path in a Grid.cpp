class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = 0;
        while(!pq.empty()){
            vector<int> it = pq.top();
            pq.pop();
            int curr = it[0];
            int i = it[1];
            int j = it[2];
            for(int x=0; x<4; x++){
                int ni = i+directions[x][0];
                int nj = j+directions[x][1];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int cost = (grid[i][j] != x+1);
                    if(cost+curr < res[ni][nj]){
                        pq.push({cost+curr, ni, nj});
                        res[ni][nj] = cost+curr;
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};