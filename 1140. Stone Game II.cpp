class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(vector<int> &piles, int per, int i, int M){
        if(i>=n)
            return 0;
        if(t[per][i][M] != -1)
            return t[per][i][M];
        int stones = 0;
        int res = (per == 1)? -1 : INT_MAX;
        for(int x=1; x<=min(2*M, n-i); x++){
            stones += piles[i+x-1];
            if(per)
                res = max(res, stones + solve(piles, 0, i+x, max(x, M)));
            else
                res = min(res, solve(piles, 1, i+x, max(x, M)));
        }
        return t[per][i][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t, -1, sizeof(t));
        return solve(piles, 1, 0, 1);
    }
};