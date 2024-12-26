class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int curr, unordered_map<string, int>&mp){
        if(i == nums.size())
            return (curr == target) ? 1 : 0;
        string key = to_string(i) + "_" + to_string(curr);
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        int plus = solve(nums, target, i+1, curr+nums[i], mp);
        int minus = solve(nums, target, i+1, curr-nums[i], mp);
        return mp[key] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
        return solve(nums, target, 0, 0, mp);
    }
};