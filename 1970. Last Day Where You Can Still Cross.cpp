class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool dfs(vector<vector<int>> &mat, int r, int c){
        if(r<0 || r>=n || c<0 || c>=m || mat[r][c])
            return false;
        if(r == n-1)
            return true;
        mat[r][c] = 1;
        for(vector<int> &d : dir){
            if(dfs(mat, r+d[0], c+d[1])){
                return true;
            }
        }
        return false;
    }
    bool check(int idx, vector<vector<int>> &cells){
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i=0; i<=idx; i++){
            int u = cells[i][0]-1;
            int v = cells[i][1]-1;
            mat[u][v] = 1;
        }
        for(int i=0; i<m; i++){
            if(mat[0][i] == 0 && dfs(mat, 0, i))
                return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;
        int l=0, h=cells.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(mid, cells)){
                res = mid+1;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};