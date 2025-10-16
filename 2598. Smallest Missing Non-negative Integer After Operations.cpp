class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            nums[i] = nums[i]%value;
            if(nums[i]<0)
                nums[i] += value;
            if(nums[i]<n)
                dp[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(dp[i%value] == 0)
                return i;
            dp[i%value]--;
        }
        return n;
    }
};