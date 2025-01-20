class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n), col(m);
        vector<pair<int, int>> mp(m*n);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                mp[mat[i][j]-1] = {i, j};
        
        for(int i=0; i<m*n; i++){
            auto &[x, y] = mp[arr[i]-1];
            if(++row[x] == m || ++col[y] == n)
                return i;
        }
        return -1;
    }
};