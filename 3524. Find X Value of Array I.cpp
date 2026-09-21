
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k));
        dp[0][nums[0]%k] = 1;
        for(int i=1; i<n; i++){
            int r = nums[i]%k;
            dp[i][r] = 1;
            for(int j=0; j<k; j++){
                dp[i][(j*r)%k] += dp[i-1][j];
            }
        }
        vector<long long> res(k);
        for(int r=0; r<k; r++){
            for(int i=0; i<n; i++)
                res[r] += dp[i][r];
        }
        return res;
    }
};ss