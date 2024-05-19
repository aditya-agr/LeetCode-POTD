class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        int n =nums.size();
        int cnt=0, loss=INT_MAX;
        for(int i=0; i<n; i++){
            if((nums[i]^k) > nums[i]){
                cnt++;
                ans += nums[i]^k;
            }
            else
                ans += nums[i];
            loss = min(loss, abs(nums[i] - (nums[i]^k))); 
        }
        if(cnt%2)
            ans -= loss;
        return ans;
    }
};