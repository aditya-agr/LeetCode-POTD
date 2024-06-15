class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> idx(n);
        for(int i=0; i<n; i++)
            idx[i] = {capital[i], profits[i]};
        sort(idx.begin(), idx.end());
        priority_queue<int> pq;
        int i=0;
        while(k--){
            while(i < n && w >= idx[i].first){
                pq.push(idx[i].second);
                i++;
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;

    }
};