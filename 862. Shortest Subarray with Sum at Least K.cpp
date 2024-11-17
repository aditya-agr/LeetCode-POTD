class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> idx(n,0);
        deque<int> dq;
        int res = INT_MAX;
        int j=0;

        while(j<n){
            if(j==0)
                idx[j] = nums[j];
            else
                idx[j] = idx[j-1] + nums[j];

            if(idx[j] >= k)
                res = min(res, j+1);

            while(!dq.empty() && idx[j]-idx[dq.front()] >= k){
                res = min(res, j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && idx[j] <= idx[dq.back()])
                dq.pop_back();
            
            dq.push_back(j);
            j++;
        }
        return res == INT_MAX ? -1 : res;
    }
};