class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int curr = grid[i][j];
        grid[i][j] = 0;
        int maxg = 0;

        for(int k=0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj])
                maxg = max(maxg, dfs(grid, ni, nj));
        }
        grid[i][j] = curr;
        return curr + maxg;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j])
                    maxGold = max(maxGold, dfs(grid, i, j));
        
        return maxGold;
    }
};