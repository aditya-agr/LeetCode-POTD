class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cumSum(n);
        cumSum[0] = nums[0];
        for(int i=1; i<n; i++)
            cumSum[i] = cumSum[i-1]+nums[i];
        
        vector<int> idx(10001, -1);
        int res = 0;
        int i=-1, j=0;
        while(j<n){
            i = max(i, idx[nums[j]] + 1);
            int isum = (i-1<0) ? 0 : cumSum[i-1];
            int curr = cumSum[j];
            res = max(res, curr-isum);
            idx[nums[j]] = j;
            j++;
        }
        return res;
    }
};