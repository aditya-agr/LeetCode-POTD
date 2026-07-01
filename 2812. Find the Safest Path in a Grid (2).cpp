class Solution {
public:
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {1,0}, {0,1}};
    int n;
    bool check(int &v, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(dp[0][0] < v)
            return false;
        vector<vector<int>> vis(n, vector<int>(n));
        queue<pair<int, int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x==n-1 && y==n-1)
                return true;
            for(auto &d : dir){
                int x_ = x+d[0];
                int y_ = y+d[1];
                if(x_>=n || x_<0 || y_>=n || y_<0 || vis[x_][y_]!=0 || dp[x_][y_]<v)
                    continue;
                vis[x_][y_] = 1;
                q.push({x_, y_});
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n =  grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int lvl = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto &d : dir){
                    int x_ = x+d[0];
                    int y_ = y+d[1];
                    if(x_>=n || x_<0 || y_>=n || y_<0 || dp[x_][y_]!=INT_MAX)
                        continue;
                    dp[x_][y_] = min(dp[x_][y_], lvl);
                    q.push({x_, y_});
                }
            }
            lvl++;
        }
        int l = 0, h = lvl;
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(mid, grid, dp)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};