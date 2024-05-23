class Solution {
public:
    int solve(vector<int>& nums, int k, int idx, unordered_map<int, int>&mp){
        if(idx==nums.size())
            return 1;
        int take=0, notake=0;
        notake = solve(nums, k, idx+1, mp);
        if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
            mp[nums[idx]]++;
            take = solve(nums, k, idx+1, mp);
            mp[nums[idx]]--;
        }
        return take+notake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        return solve(nums, k, 0, mp)-1;
    }
};