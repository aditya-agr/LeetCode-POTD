class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int r = 0, l = 0;
        for(int x : nums)
            r += x;
            
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            l += nums[i];
            r -= nums[i];
            if(abs(r-l)%2 == 0)
                cnt++;
        }
        return cnt;
    }
};