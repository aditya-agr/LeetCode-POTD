class Solution {
public:
    long long dp[1001][501][4];
    long long solve(int i, int k, int c, vector<int> &prices){
        if(i == prices.size()){
            if(c == 0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][k][c] != INT_MIN)
            return dp[i][k][c];
        long long notake = solve(i+1, k, c, prices);
        long long take = 0;
        if(k > 0){
            if(c == 1)
                take = - prices[i] + solve(i+1, k-1, 0, prices);
            else if(c == 2)
                take = prices[i] + solve(i+1, k-1, 0, prices);
            else
                take = max(prices[i] + solve(i+1, k, 1, prices), 
            - prices[i] + solve(i+1, k, 2, prices));

        }
        return dp[i][k][c] = max(take, notake);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                for(int x=0; x<=3; x++)
                    dp[i][j][x] = INT_MIN;
            
        return solve(0, k, 0, prices);
    }
};