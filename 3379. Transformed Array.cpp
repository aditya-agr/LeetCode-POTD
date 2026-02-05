class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                int idx = nums[i]%n;
                idx = (i+idx)%n;
                res[i] = nums[idx];
            }
            else if(nums[i] < 0){
                int idx = abs(nums[i])%n;
                idx = (i-idx+n)%n;
                res[i] = nums[idx];
            }
            else
                res[i] = nums[i];
        }
        return res;
    }
};