class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> tmp(n, vector<int>(m));
        bool res = false;
        for(int k=0; k<4; k++){
            bool cur = true; 
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(mat[i][j] != target[j][m-i-1])
                        cur = false;
                    tmp[j][m-i-1] = mat[i][j];
                }
            }
            mat = tmp;
            res |= cur;
        }
        return res;
    }
};