class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<long long> rooms(n), cnt(n);
        sort(meetings.begin(), meetings.end());
        
        for(vector<int> &meet : meetings){
            long long u = meet[0];
            long long v = meet[1];
            long long idx=-1, mn=LLONG_MAX;
            for(int i=0; i<n; i++){
                if(rooms[i] <= u){
                    idx = i;
                    break;
                }
                if(rooms[i] < mn){
                    mn = rooms[i];
                    idx = i;
                }
            }
            rooms[idx] = max(v, rooms[idx]+(v-u));
            cnt[idx]++;
        }
        int mx=0, idx=-1;
        for(int i=0; i<n; i++){
            if(mx < cnt[i]){
                mx = cnt[i];
                idx = i;
            }
        }
        return idx;
    }
};