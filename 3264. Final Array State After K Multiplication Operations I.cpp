#define P pair<int, int> 
class Solution {
public:
    vector<int> getFinalState(vector<int> nums, int k, int multiplier) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        while(k--){
            auto it = pq.top();
            pq.pop();
            int idx = it.second;
            nums[idx] *= multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};