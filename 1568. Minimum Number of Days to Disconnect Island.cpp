class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j])
            return;
        grid[i][j] = 0;
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }
    int numberofIsland(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                if(grid[i][j]){
                    cnt++;
                    dfs(grid, i, j);
                }
             }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int num = numberofIsland(grid);
        if(num != 1)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int cnt = numberofIsland(grid);
                    if(cnt!=1) return 1;
                    grid[i][j]=1;
                }

             }
        }
        return 2;
    }
};