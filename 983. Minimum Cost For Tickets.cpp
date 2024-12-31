class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int> &dp){
        int n = days.size();
        if(idx >= n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int day1 = costs[0] + solve(days, costs, idx+1, dp);
        int mx7days = days[idx] + 7;
        int j = idx;
        while(j<n && days[j] < mx7days)
            j++;
        int day7 = costs[1] + solve(days, costs, j, dp);
        int mx30days = days[idx] + 30;
        j = idx;
        while(j<n && days[j] < mx30days)
            j++;
        int day30 = costs[2] + solve(days, costs, j, dp);

        return dp[idx] = min(day1, min(day7, day30));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(days, costs, 0, dp);
    }
};