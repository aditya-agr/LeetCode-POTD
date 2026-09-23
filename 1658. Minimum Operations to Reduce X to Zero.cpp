class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long tot = 0;
        for(int num : nums)
            tot += num;
        
        if(tot < x)
            return -1;
        
        int rem = tot-x;
        if (rem == 0) return n;
        unordered_map<int, int>  mp;
        mp[0] = -1;
        int sum = 0, res = -1; 
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.count(sum-rem))
                res = max(res, i-mp[sum-rem]);
            mp[sum] = i;
            
        }
        return res == -1 ? res : n-res;
    }
};ss