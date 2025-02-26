class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++){
            curr = max(nums[i], curr+nums[i]);
            maxSum = max(curr, maxSum);
        }
        curr = nums[0];
        int minSum = nums[0];
        for(int i=1; i<n; i++){
            curr = min(nums[i], curr+nums[i]);
            minSum = min(curr, minSum);
        }
        return max(abs(maxSum), abs(minSum));
    }
};