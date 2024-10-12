class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        for(auto &x : intervals){
            int ed = x[1];
            pq.push(ed);
            if(pq.top() < st)
                pq.pop();
        }
        return pq.size();
    }
};