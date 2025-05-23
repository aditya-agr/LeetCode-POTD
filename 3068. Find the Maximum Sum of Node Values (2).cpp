class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long res = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if((nums[i]^k) > nums[i]){
                nums[i] = nums[i]^k;
                cnt++;
            }
            res += nums[i];
        }
        int loss = INT_MAX;
        if(cnt%2){
            for(int i=0; i<n; i++){
                loss = min(loss, nums[i]-(nums[i]^k));
            }
            return res-loss;
        }
        return res;
    }
};