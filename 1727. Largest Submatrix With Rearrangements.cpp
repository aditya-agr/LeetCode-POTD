class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i-1][j] >= 1 && matrix[i][j] == 1)
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        int res = 0;
        for(int i=n-1; i>=0; i--){
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j=0; j<m; j++)
                res = max(res, matrix[i][j]*(j+1));
        }
        return res;
    }
};