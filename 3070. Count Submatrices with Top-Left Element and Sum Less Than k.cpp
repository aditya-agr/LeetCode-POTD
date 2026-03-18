class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            int prev = 0;
            for(int j=0; j<m; j++){
                prev += grid[i][j];
                grid[i][j] = prev;
                if(i > 0)
                    grid[i][j] += grid[i-1][j];
                if(grid[i][j] <= k)
                    cnt++;
            }
        }
        return cnt;
    }
};