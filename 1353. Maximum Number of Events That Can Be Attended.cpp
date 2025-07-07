class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int d = events[0][0];
        int i = 0;
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        while(i<n){
            while(i<n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            } 
            d++;
            if(!pq.empty()){
                count++;
                cout<<pq.top();
                pq.pop();
            }
            else
                d = events[i][0];
            while(!pq.empty() && pq.top()<d)
                pq.pop();
        }
        while(!pq.empty()){
            if(pq.top() < d){
                pq.pop();
                continue;
            } 
            pq.pop();
            count++;
            d++;
        }
        return count;
    }
};