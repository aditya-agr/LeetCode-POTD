class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long mod = 1e9+7;
        for(vector<int> &q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];
            int idx = l;
            while(idx <= r){
                long long res = nums[idx];
                res = (res*v)%mod;
                nums[idx] = res;
                idx += k;
            }
        }
        int xr = 0;
        for(int &num : nums){
            xr ^= num;
        }
        return xr;
    }
};