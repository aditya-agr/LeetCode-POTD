class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            nums[i] = __gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        long long res = 0;
        while(i<j){
            res += __gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return res;
    }
};