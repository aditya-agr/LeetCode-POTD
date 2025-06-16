class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int mn = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > mn)
                res = max(res, nums[i]-mn);
            mn = min(mn, nums[i]);
        }
        return res;
    }
};