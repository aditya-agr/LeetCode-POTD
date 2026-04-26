class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;
    bool dfs(int pi, int pj, int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
        if(vis[i][j])
            return true;
        vis[i][j] = 1;
        for(vector<int> &d : dir){
            int i_ = i+d[0];
            int j_ = j+d[1];
            if(i_==pi && j_==pj)
                continue;
            if(i_<0 || i_>=n || j_<0 || j_>=m)
                continue;
            if(grid[i_][j_] == grid[i][j] && dfs(i, j, i_, j_, vis, grid))
                return true;                
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && dfs(-1, -1, i, j, vis, grid))
                    return true;
            }
        }
        return false;
    }
};