class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = -1;
        int curr = 1;
        int cnt = 1;
        int n = nums.size();
        nums.push_back(INT_MIN);
        int res = 1;
        for(int i=1; i<=n; i++){
            if(nums[i] > nums[i-1])
                cnt++;
            else{
                prev = curr;
                curr = cnt;
                cnt = 1;
                res = max(res, min(curr, prev));
                res = max(res, max(curr, prev)/2);
            }
        }
        return res;
    }
};