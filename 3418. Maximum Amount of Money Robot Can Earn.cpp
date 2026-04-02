class Solution {
public:
    
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        dp[0][0][0] = coins[0][0]; 
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; 
        }
        
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[0][j-1][k] != INT_MIN) {
                    dp[0][j][k] = dp[0][j-1][k] + coins[0][j];
                }
                
                if (k > 0 && dp[0][j-1][k-1] != INT_MIN && coins[0][j] < 0) {
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k-1]);
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i-1][0][k] != INT_MIN)
                    dp[i][0][k] = dp[i-1][0][k] + coins[i][0];
                
                if (k > 0 && dp[i-1][0][k-1] != INT_MIN && coins[i][0] < 0) 
                    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k-1]);
            }
        }
    
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i-1][j][k] != INT_MIN) 
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + coins[i][j]);
                    
                    if (dp[i][j-1][k] != INT_MIN) 
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + coins[i][j]);
            
                    
                    if (k > 0 && coins[i][j] < 0) {
                        if (dp[i-1][j][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                        
                        if (dp[i][j-1][k-1] != INT_MIN) 
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }
        
        int maxProfit = INT_MIN;
        for (int k = 0; k < 3; k++) {
            maxProfit = max(maxProfit, dp[m-1][n-1][k]);
        }
        return maxProfit;
    }
};