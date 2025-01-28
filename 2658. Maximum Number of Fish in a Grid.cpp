class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r<0 || r>=n || c<0 || c>=m || !grid[r][c])
            return 0;
        int tot = grid[r][c];
        grid[r][c] = 0;
        for(int i=0; i<4; i++)
            tot += dfs(r+dir[i][0], c+dir[i][1], grid);
        return tot;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    int curr = dfs(i, j, grid);
                    res = max(res, curr);
                }
            }
        }
        return res;
    }
};