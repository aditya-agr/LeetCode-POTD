
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = INT_MIN;
        mx = max(mx, nums[n-1]*nums[n-2]*nums[n-3]);
        mx = max(mx, nums[n-1]*nums[0]*nums[1]);
        if(nums[n-1] == 0 && n > 3)
            mx = max(mx, nums[n-4]*nums[n-2]*nums[n-3]);
        return mx;
    }
};