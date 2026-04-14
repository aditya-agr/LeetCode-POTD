class Solution {
public:
    long long dp[101][10001];
    long long solve(int i, int j, vector<int>& robot, vector<int>& factory){
        int n = robot.size();
        int m = factory.size();
        if(i==n)
            return 0;
        if(j==m)
            return LLONG_MAX/2;
        if(dp[i][j] != -1)
            return dp[i][j];
        long long take = abs(robot[i]-factory[j]) + solve(i+1, j+1, robot, factory);
        long long skip = solve(i, j+1, robot, factory);
        return dp[i][j] = min(take, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> fact;
        for(int i=0; i<m; i++){
            for(int j=0; j<factory[i][1]; j++)
                fact.push_back(factory[i][0]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, robot, fact);
    }
};ss