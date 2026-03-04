Max Xor Subarray of size Kclass Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n), col(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] && row[i]==1 && col[j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};