class Solution {
public:
    vector<vector<int>> preSum;
    int n, m;
    bool check(int threshold, int k){

        for(int i=0; i<=n-k; i++){

            int currSum = 0;
            for(int r=i; r<i+k; r++)
                currSum += preSum[r][k-1];

            if(currSum <= threshold)
                return true;

            for(int j=k; j<m; j++){
                currSum = 0;
                for(int r=i; r<i+k; r++){
                    currSum += preSum[r][j] - preSum[r][j-k];
                }
                if(currSum <= threshold)
                    return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();
        preSum.resize(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
            preSum[i][0] = mat[i][0];
        for(int i=0; i<n; i++){
            for(int j = 1; j<m; j++)
                preSum[i][j] += mat[i][j] + preSum[i][j-1];
        } 

        int res = 0;
        int l = 1, h = min(n, m);
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(threshold, mid)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};