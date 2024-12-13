
#define P pair<int, int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        vector<int> idx(n);
        while(!pq.empty()){
            P it = pq.top();
            pq.pop();
            int i = it.second;
            if(idx[i] != 0)
                continue;
            score += it.first;
            idx[i]++;
            if(i<n-1) idx[i+1]++;
            if(i>0) idx[i-1]++;
        }
        return score;
    }
};