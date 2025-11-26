class Solution {
public:
    int n, m;
    int mod = 1e9+7;
    // int solve(int i, int j, int curr, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    //     if(i<0 || i>=n || j<0 || j>=m)
    //         return 0;
    //     curr += grid[i][j];
    //     if(i == n-1 && j == m-1)
    //         return curr%k == 0 ? 1 : 0;
    //     curr %= k;
    //     if(dp[i][j][curr] != -1)
    //         return dp[i][j][curr];
    //     int left = solve(i+1, j, curr%k, k, grid, dp);
    //     int right = solve(i, j+1, curr%k, k, grid, dp);

    //     return dp[i][j][curr] = (left+right)%mod;
    // }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        // return solve(0, 0, 0, k, grid, dp);

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        for(int curr=0; curr<k; curr++){
            dp[n-1][m-1][curr] = (curr + grid[n-1][m-1])%k == 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1)
                    continue;   
                for(int curr=0; curr<k; curr++){
                    int r = (curr+grid[i][j])%k;
                    dp[i][j][curr] = (dp[i+1][j][r]+dp[i][j+1][r])%mod;
                }
            }
        }
        return dp[0][0][0];
    }
};s