class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = abs(nums.back()-nums[0]);
        int n = nums.size();
        for(int i=0; i<n-1; i++)
            res = max(res, abs(nums[i]-nums[i+1]));
        return res;
    }
};