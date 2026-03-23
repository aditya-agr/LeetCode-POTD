#define ll long long
class Solution {
public:
    int n, m;
    ll mod = 1e9+7;
    vector<vector<pair<ll,ll>>> dp;
    pair<ll,ll> solve(int i, int j, vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)
            return {grid[n-1][m-1], grid[n-1][m-1]};
        pair<ll,ll> res = {LLONG_MIN, LLONG_MAX};
        if(dp[i][j] != res)
            return dp[i][j];
        if(i<n-1){
            pair<ll,ll> right = solve(i+1, j, grid);
            res.first = max({res.first, grid[i][j]*right.first, grid[i][j]*right.second});
            res.second = min({res.second, grid[i][j]*right.first, grid[i][j]*right.second});
        }
        if(j<m-1){
            pair<ll,ll> down = solve(i, j+1, grid);
            res.first = max({res.first, grid[i][j]*down.first, grid[i][j]*down.second});
            res.second = min({res.second, grid[i][j]*down.first, grid[i][j]*down.second});
        }
        return dp[i][j] = res;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<pair<ll,ll>>>(n, vector<pair<ll,ll>>(m, {LLONG_MIN, LLONG_MAX}));
        auto res = solve(0, 0, grid);
        if(res.first < 0)
            return -1;
        return res.first%mod;
    }
};