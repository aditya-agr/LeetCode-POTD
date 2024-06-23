class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P> mxq;
        priority_queue<P, vector<P>, greater<P>> mnq;
        int i = 0;
        int j = 0;
        int res = 0;
        while (j < n) {
            mxq.push({nums[j], j});
            mnq.push({nums[j], j});
            while (mxq.top().first - mnq.top().first > limit) {
                i = min(mxq.top().second, mnq.top().second) + 1;
                while (mxq.top().second < i) 
                    mxq.pop();
                while (mnq.top().second < i) 
                    mnq.pop();
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};