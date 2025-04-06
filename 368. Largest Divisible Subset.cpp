class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), hash(n);
        int maxi = 0, idx = -1;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                idx = i;
            }
        }
        vector<int> res;
        res.push_back(nums[idx]);
        while(hash[idx] != idx){
            idx = hash[idx];
            res.push_back(nums[idx]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};