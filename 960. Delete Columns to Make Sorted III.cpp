class Solution {
public:
    int n, m;
    int res;
    int dp[101][102][101];
    void solve(int u, int p, int cnt, vector<string>& strs){
        if(u == m){
            res = min(res, m-cnt);
            return;
        }
        if(dp[u][p+1][cnt] != -1){
            res = min(res, m-dp[u][p+1][cnt]);
            return;
        }
        solve(u+1, p, cnt, strs);
        bool take = true;
        if(p != -1){
            for(int i=0; i<n; i++){
                if(strs[i][u] < strs[i][p]){
                    take = false;
                    break;
                }
            }
            if(take)
                solve(u+1, u, cnt+1, strs);
        }
        else
            solve(u+1, u, cnt+1, strs);
        dp[u][p+1][cnt] = cnt;
    }
    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        m = strs[0].size();
        res = INT_MAX;
        memset(dp, -1, sizeof(dp));
        solve(0, -1, 0, strs);
        return res;
    }
};