#define pll pair<long long, int>
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        int n = workerTimes.size();
        vector<long long> cnt(n, 2);
        for(int i=0; i<n; i++){
            pq.push({workerTimes[i], i});
        }
        long long res = 0;
        while(mountainHeight){
            long long cur = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            res = max(res, cur);
            long long nxt = cur+workerTimes[idx]*cnt[idx];
            pq.push({nxt, idx});
            cnt[idx]++;
            mountainHeight--;
        }
        return res;
    }
};