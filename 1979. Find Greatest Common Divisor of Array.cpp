class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = 0;
        int mn = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        return __gcd(mn, mx);
    }
};