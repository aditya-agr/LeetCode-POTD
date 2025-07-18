class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long> left(3*n), right(3*n);
        priority_queue<long long> mxpq;
        priority_queue<long long, vector<long long>, greater<long long>> mnpq;
        left[0] = nums[0];
        mxpq.push(nums[0]);
        for(int i=1; i<2*n; i++){
            mxpq.push(nums[i]);
            left[i] = left[i-1] + nums[i];
            if(mxpq.size() > n){
                left[i] -= mxpq.top();
                mxpq.pop();
            }
        }
        right[3*n-1] = nums[3*n-1];
        mnpq.push(nums[3*n-1]);
        for(int i=3*n-2; i>=n; i--){
            mnpq.push(nums[i]);
            right[i] = right[i+1] + nums[i];
            if(mnpq.size() > n){
                right[i] -= mnpq.top();
                mnpq.pop();
            }
        }
        long long res = LONG_LONG_MAX;
        for(int i=n-1; i<2*n; i++){
            res = min(res, left[i]-right[i+1]);
        }
        return res;
    }
};