class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
            pq.push(nums[i]);
        long long score=0;
        for(int i=0; i<k; i++){
            score += pq.top();
            int temp = pq.top();
            pq.pop();
            pq.push((temp+2)/3);
        }
        return score;
    }
};