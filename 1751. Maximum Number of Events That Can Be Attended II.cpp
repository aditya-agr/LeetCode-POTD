

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        vector<int> next(n, n);
        for(int i=0; i<n; i++){
            vector<int> v = {events[i][1], INT_MAX, INT_MAX};
            next[i] = upper_bound(events.begin()+i+1, events.end(), v) - events.begin();
        }
        for(int i=n-1; i>=0; i--){
            for(int K=1; K<=k; K++){
                dp[i][K] = max(dp[i+1][K], events[i][2] + dp[next[i]][K-1]);
            }
        }
        return dp[0][k];
    }
};



class Solution {
public:
    vector<vector<int>> dp;
    vector<int> next;
    int solve(vector<vector<int>>& events, int idx, int k){
        int n = events.size();
        if(idx>=n || k==0)
            return 0;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        int skip = solve(events, idx+1, k);
        int take = events[idx][2] + solve(events, next[idx], k-1);
        return dp[idx][k] = max(skip, take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp.assign(n+1, vector<int>(k+1, -1));
        next.assign(n, n);
        for(int i=0; i<n; i++){
            vector<int> v = {events[i][1], INT_MAX, INT_MAX};
            int j = upper_bound(events.begin()+i+1, events.end(), v)-events.begin();
            next[i] = j; 
        }
        return solve(events, 0, k);
    }
};