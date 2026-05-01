class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long tot = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            tot += nums[i]*i;
        }
        long long res = tot;
        for(int i=n-1; i>=1; i--){
            tot += sum;
            tot -= n*nums[i];
            res = max(res, tot);
        }
        return res;
    }
};