class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int mnk = -1;
        int mxk = -1;
        int ctk = -1;
        long long res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == minK)
                mnk = i;
            if(nums[i] == maxK)
                mxk = i;
            if(nums[i] > maxK || nums[i] < minK)
                ctk = i;
            int small = min(mnk, mxk);
            int temp = small - ctk;
            res += (temp <= 0) ? 0 : temp;
        }
        return res;
    }
};