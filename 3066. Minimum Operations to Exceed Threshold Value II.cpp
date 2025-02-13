class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int cnt = 0;
        while(pq.top()<k){
            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();
            pq.push(f*2+s);
            cnt++;
        }
        return cnt;
    }
};