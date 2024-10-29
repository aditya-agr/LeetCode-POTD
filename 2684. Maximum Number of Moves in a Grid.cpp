class Solution {
public:
    int n, m;
    vector<int> dir = {-1, 0 , 1};
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int moves=0;
        for(int x : dir){
            int new_i = i+x;
            int new_j = j+1;
            if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && grid[i][j]<grid[new_i][new_j])
                moves = max(moves, 1+solve(new_i, new_j, grid, dp));
        }
        
        return dp[i][j] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int mxMoves = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++)
            mxMoves = max(mxMoves, solve(i, 0, grid, dp));
        return mxMoves;
    }
};