class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt=0, idx=0;
        for(int i=0; i<n; i++){
            idx = max(idx, nums[i]);
            cnt += (idx-nums[i]);
            idx++;
        }
        return cnt;
    }
};