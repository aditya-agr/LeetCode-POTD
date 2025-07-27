class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int i = 1;
        while(i<n-1 && nums[i]==nums[i-1])
            i++;
        while(i<n-1){
            int j = i+1;
            while(j<n-1 && nums[j]==nums[i]) j++;
            if(nums[i]>nums[i-1] && nums[i]>nums[j])
                cnt++;
            if(nums[i]<nums[i-1] && nums[i]<nums[j])
                cnt++;
            i = j;
        }
        return cnt;
    }
};