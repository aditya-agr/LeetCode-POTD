class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tot = 0;
        for(int x : nums){
            tot += x;
            tot %= p;
        }
        if(tot == 0)
            return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = nums.size();
        int curr = 0, res = INT_MAX;
        for(int i=0; i<n; i++){
            curr += nums[i];
            curr = curr%p;
            int rem = (curr-tot+p)%p;
            if(mp.count(rem))
                res = min(res, i-mp[rem]);
            mp[curr] = i;
        }
        return (res==INT_MAX || res==n) ? -1 : res;
    }
};