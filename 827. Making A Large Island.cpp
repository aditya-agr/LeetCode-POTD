class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0},{-1, 0}};
    int n, m;
    int bfs(vector<vector<int>>& grid, int i, int j, int u){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = u;
        int len = 1;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(auto d : dir){
                int x_ = x+d[0];
                int y_ = y+d[1];
                if(x_>=0 && x_<n && y_>=0 && y_<m && grid[x_][y_]==1){
                    q.push({x_, y_});
                    grid[x_][y_] = u;
                    len++;
                }
            }
        }
        return len;
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        n = grid.size();
        m = grid[0].size();
        int uniq = 2;
        int mxlen = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int len = bfs(grid, i, j, uniq);
                    mp[uniq] = len;
                    mxlen = max(mxlen, len);
                    uniq++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    int len = 1;
                    unordered_set<int> seen;
                    for(auto d : dir){
                        int x_ = i+d[0];
                        int y_ = j+d[1];
                        if(x_>=0 && x_<n && y_>=0 && y_<m && grid[x_][y_]){
                            int idx = grid[x_][y_];
                            if(seen.count(idx) == 0)
                                len += mp[idx];
                            seen.insert(idx);
                        }
                    }
                    mxlen = max(mxlen, len);
                }
            }
        }
        return mxlen;
    }
};