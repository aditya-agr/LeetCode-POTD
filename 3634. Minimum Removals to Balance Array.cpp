class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int i, int j, int &k, vector<int> &nums){
    //     if(1LL*nums[j] <= 1LL*nums[i]*k)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int front = 1 + solve(i+1, j, k, nums);
    //     int back = 1 + solve(i, j-1, k, nums);
    //     return dp[i][j] = min(front, back);
    // }
    int minRemoval(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // dp.resize(n, vector<int>(n, -1));
        // return solve(0, n-1, k, nums);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j=0, res=INT_MAX;
        while(j<n){
            while(1LL*nums[i]*k < 1LL*nums[j])
                i++;
            res = min(res, n-(j-i+1));
            j++;
        }
        return res;
        
    }
};