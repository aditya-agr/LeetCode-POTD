class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = 0;
        long long mn = LLONG_MAX;
        for(long long x : nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        return k*(mx-mn);
    }
};