class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            double long prod = nums[i];
            long long g = nums[i], l = nums[i];
            for(int j=i+1; j<n; j++){
                double long num = nums[j];
                prod *= num;
                g = __gcd(g, nums[j]*1LL);
                l = lcm(l, nums[j]*1LL);
                if(prod/g == l)
                    res = max(res, j-i+1);
            }
        }
        return res;
    }
};