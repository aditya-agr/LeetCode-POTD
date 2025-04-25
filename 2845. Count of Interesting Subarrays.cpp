class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        int n = nums.size();
        vector<int> idx(n, 0);
        for(int i=0; i<n; i++){
            if(nums[i]%modulo == k)
                idx[i] = 1;
        }
        for(int i=1; i<n; i++)
            idx[i] += idx[i-1];
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            int r1 = idx[i]%modulo;
            int r2 = (r1 - k + modulo) % modulo;
            res += mp[r2];
            mp[r1]++;
        }
        return res;
    }
};