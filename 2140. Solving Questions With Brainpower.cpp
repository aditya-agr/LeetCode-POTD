class Solution {
public:
    long long solve(int idx, vector<vector<int>> &ques, vector<long long> &dp){
        if(idx >= ques.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        long long take = ques[idx][0] + solve(idx+ques[idx][1]+1, ques, dp);
        long long notake = solve(idx+1, ques, dp);
        return dp[idx] = max(take, notake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, questions, dp);
    }
};