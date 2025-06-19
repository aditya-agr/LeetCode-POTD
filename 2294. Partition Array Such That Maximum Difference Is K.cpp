class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> dp(mx+1);
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            mn = min(mn, nums[i]);
            dp[nums[i]]++;
        }
        
        int res = 1;
        for(int i=0; i<=mx; i++){
            if(dp[i] && i-mn > k){
                mn = i;
                res++;
            }
        }
        return res;
    }
};