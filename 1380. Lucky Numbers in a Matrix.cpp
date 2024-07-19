class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n, INT_MAX), col(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] = min(row[i], mat[i][j]);
                col[j] = max(col[j], mat[i][j]);
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == col[j])
                    res.push_back(row[i]);
            }
        }
        return res;
    }
};