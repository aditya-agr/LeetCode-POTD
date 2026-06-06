class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int tot = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
            tot += nums[i];
        vector<int> res(n);
        int cur = 0;
        for(int i=0; i<n; i++){
            cur += nums[i];
            res[i] = abs(tot-cur);
            tot -= nums[i];
        }
        return res;
    }
};