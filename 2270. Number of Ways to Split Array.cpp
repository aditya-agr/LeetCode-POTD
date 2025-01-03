class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = 0;
        for(int x : nums)
            tot += x;
        int n = nums.size(), cnt = 0;
        long long curr=0;
        for(int i=0; i<n-1; i++){
            curr += nums[i];
            tot -= nums[i];
            if(curr>=tot)
                cnt++;
        }
        return cnt;
    }
};