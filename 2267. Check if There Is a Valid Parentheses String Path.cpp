class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, int cnt, vector<vector<char>> &grid){
        if(i>=n || j>=m)
            return false;
        if(i==n-1 && j==m-1){
            cnt += (grid[i][j] == '(' ? 1 : -1);
            return cnt == 0;
        }
        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];
        bool a, b;
        if(grid[i][j] == ')'){
            if(cnt == 0)
                return false;
            a = solve(i+1, j, cnt-1, grid);
            b = solve(i, j+1, cnt-1, grid);
        }
        else{
            a = solve(i+1, j, cnt+1, grid);
            b = solve(i, j+1, cnt+1, grid);
        }
        return dp[i][j][cnt] = a || b;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if((n+m-1)%2 || grid[0][0]==')' || grid[n-1][m-1]=='(')
            return false;
        dp.resize(n, vector<vector<int>>(m, vector<int>(n+m, -1)));
        return solve(0, 0, 0, grid);
    }
};