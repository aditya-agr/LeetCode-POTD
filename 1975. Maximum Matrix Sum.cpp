class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] < 0){
                    neg++;
                }
                mn = min(mn, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(neg%2)
            sum -= 2*mn;
        return sum;
    }
};