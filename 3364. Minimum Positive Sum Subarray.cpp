class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        int n = nums.size();
        r = min(r, n);
        for(int i=l; i<=r; i++){
            int sum = 0, j = 0;
            while(j<i)
                sum += nums[j++];
            if(sum > 0) res = min(res, sum);
            while(j<n){
                sum -= nums[j-i];
                sum += nums[j];
                if(sum > 0) res = min(res, sum);
                j++;
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};