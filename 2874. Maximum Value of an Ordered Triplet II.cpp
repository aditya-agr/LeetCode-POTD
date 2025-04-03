class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        for(int i=1; i<n; i++)
            left[i] = max(left[i-1], nums[i-1]);
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i+1], nums[i+1]);
        long long res = 0;
        for(int j=0; j<n; j++)
            res = max(res, (long long)(left[j]-nums[j])*right[j]);
        return res;
    }
};