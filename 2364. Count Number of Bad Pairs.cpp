class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long tot = n, cnt = 0;
        tot = tot*(tot-1)/2;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int curr = nums[i]-i;
            cnt += mp[curr];
            mp[curr]++;
        }
        return tot - cnt;
    }
};