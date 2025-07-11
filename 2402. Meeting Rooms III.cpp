#define P pair<long long, int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<P, vector<P>, greater<P>> used;
        priority_queue<int, vector<int>, greater<int>> avail;
        for(int i=0; i<n ;i++)
            avail.push(i);
        
        vector<int> cnt(n);
        for(int i=0; i<m; i++){
            int st = meetings[i][0];
            int ed = meetings[i][1];
            int d = ed-st;

            while(!used.empty() && used.top().first <= st){
                avail.push(used.top().second);
                used.pop();
            }
            if(!avail.empty()){
                int room = avail.top();
                avail.pop();
                cnt[room]++;
                used.push({ed, room});
            }
            else{
                int room = used.top().second;
                long long t = used.top().first;
                used.pop();
                cnt[room]++;
                used.push({t+d, room});
            }
        }
        int res=0, mx=0;
        for(int i=0; i<n; i++){
            if(mx < cnt[i]){
                mx = cnt[i];
                res = i;
            }
        }
        return res;
    }
};