class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long tot = 0;
        int cnt = 0, mn = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] < 0)
                    cnt++;
                mn = min(mn, abs(matrix[i][j]));
                tot += abs(matrix[i][j]);
            }
        }
        if(cnt%2)
            tot -= 2*mn;
        return tot;
    }
};