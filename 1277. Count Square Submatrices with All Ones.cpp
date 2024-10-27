class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i>=n || j>=m || matrix[i][j]==0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i+1, j, matrix, dp);
        int diag = solve(i+1, j+1, matrix, dp);
        int down = solve(i, j+1, matrix, dp);
        return dp[i][j] = 1 + min(right, min(down, diag));
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> idx(n, vector<int>(m, -1));

        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cnt += solve(i, j, matrix, idx);

        return cnt;

    }
};