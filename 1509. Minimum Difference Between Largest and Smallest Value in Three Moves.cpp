class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        if(n<5) return 0;
        for(int i=0; i<4; i++)
            mn = min(mn, nums[n+i-4] - nums[i]);
        return mn;
    }
};