class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int trans[6][4] = {{-1, 1, -1, 3},
                       {0, -1, 2, -1},
                       {3, 2, -1, -1},
                       {1, -1, -1, 2},
                       {-1, 0, 3, -1},
                       {-1, -1, 1, 0}};
    int start[6][2] = {{1,3}, {0,2}, {2,3}, {1,2}, {0,3}, {0,1}};
    bool check(int di, vector<vector<int>> &grid){
        int r = dir[di][0];
        int c = dir[di][1];
        int vis[301][301];
        memset(vis, 0, sizeof(vis));

        while(r>=0 && r<n && c>=0 && c<m){
            if(vis[r][c] == 1)
                return false;
            vis[r][c] = 1;

            di = trans[grid[r][c]-1][di];
            if(di == -1)
                return false;
            if(r == n-1 && c == m-1)
                return true;
            
            r += dir[di][0];
            c += dir[di][1];
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(n==1 && m==1)
            return true;
        if(grid[0][0] == 5 || grid[n-1][m-1] == 4)
            return false;
        const int *s = start[grid[0][0]-1];
        return check(s[0], grid) || check(s[1], grid);
    }
};