short dp[201][201][1001];
class Solution {
public:
    int n, m;
    int solve(int i, int j, int cost, vector<vector<int>>& grid, int &k){
        if(i>=n || j>=m || cost>k)
            return SHRT_MIN;

        if(dp[i][j][cost] != -1)
            return dp[i][j][cost];

        int ncost = cost + grid[i][j];
        if(grid[i][j] == 2)
            ncost -= 1;
        
        if(ncost > k)
            return dp[i][j][cost] = SHRT_MIN;
        
        if(i==n-1 && j==m-1)
            return dp[i][j][cost] = grid[i][j];

        
        int down = solve(i+1, j, ncost, grid, k);
        int right = solve(i, j+1, ncost, grid, k);
        int best = max(down, right);
        if(best == INT_MIN)
            return dp[i][j][cost] = SHRT_MIN;

        return dp[i][j][cost] = best+grid[i][j];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, grid, k);
        return ans < 0 ? -1 : ans;
    }
};