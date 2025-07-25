class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] != nums[i+1] && nums[i] >= 0)
                sum += nums[i];
        }
        return sum;
    }
};