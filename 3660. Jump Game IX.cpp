class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pre(n), suf(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++)
            pre[i] = max(nums[i], pre[i-1]);

        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            suf[i] = min(nums[i], suf[i+1]);

        res[n-1] = pre[n-1];
        for(int i=n-2; i>=0; i--){
            if(suf[i+1] < pre[i])
                res[i] = res[i+1];
            else
                res[i] = pre[i];
        }    

        return res;
    }
};