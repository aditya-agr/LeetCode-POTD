class Solution {
public:
    double pour;
    double solve(int i, int j, vector<vector<double>> &dp){
        if(i<0 || j<0 || i<j)
            return 0;
        if(i==0 && j==0)
            return pour;
        if(dp[i][j] != -1)
            return dp[i][j];
        double left = (solve(i-1, j-1, dp)-1)/2.0;
        double right = (solve(i-1, j, dp)-1)/2.0;
        if(left<0) left = 0;
        if(right<0) right = 0;
        return dp[i][j] = left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        pour = poured;
        vector<vector<double>> dp(query_row+1, vector<double>(query_glass+1, -1));
        return min(1.0, solve(query_row, query_glass, dp));
    }
};