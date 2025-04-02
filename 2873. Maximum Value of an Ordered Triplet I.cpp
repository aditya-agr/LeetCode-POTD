class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxdiff = 0;
        int maxi = 0;
        int n = nums.size();
        long long res = 0;
        for(int k=0; k<n; k++){
            res = max(res, (long long)maxdiff*nums[k]);
            maxdiff = max(maxdiff, maxi - nums[k]);
            maxi = max(maxi, nums[k]);
        }
        return res;
    }

    
};