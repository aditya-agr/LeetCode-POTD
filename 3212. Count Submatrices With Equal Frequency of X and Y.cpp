class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'X')
                    dp[i][j] = 1;
                if(grid[i][j] == 'Y')
                    dp[i][j] = -1;
                if(grid[i][j] == '.')
                    dp[i][j] = 0;
            }
        }
        vector<int> col(m);
        int cnt = 0;
        for(int i=0; i<n; i++){
            int prev = 0, hasX = 0;
            for(int j=0; j<m; j++){
                if(dp[i][j] == 1)
                    col[j] = 1;
                hasX += col[j];

                prev += dp[i][j];
                dp[i][j] = prev;
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
                if(dp[i][j]==0 && hasX)
                    cnt++;
            }
        }
        return cnt;
    }
};