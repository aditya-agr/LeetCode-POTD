class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long curr = 0, res = LLONG_MIN;
        vector<long long> mp(k, LLONG_MAX/2);
        mp[k-1] = 0;
        for(int i=0; i<n; i++){
            curr += nums[i];
            res = max(res, curr-mp[i%k]);
            mp[i%k] = min(mp[i%k], curr);
        }
        return res;
    }
};