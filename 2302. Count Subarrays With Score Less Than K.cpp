class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long res = 0;
        long long sum = 0;
        while(j<n){
            sum += nums[j];
            long long score = sum * (j-i+1);
            while(score>=k){
                sum -= nums[i];
                i++;
                score = sum * (j-i+1);
            }
            res += (j-i+1);
            j++;
        }
        return res;
    }
};