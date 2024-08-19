class Solution {
public:
    int t[1001][1001];
    int solve(int curr, int past, int n){
        if(curr == n)
            return 1;
        if(curr > n)
            return 10000;
        if(t[curr][past]!=-1)
            return t[curr][past];
        int CAP = 2 + solve(curr+curr, curr, n);
        int P = 1 + solve(curr+past, past, n);
        return t[curr][past] = min(CAP, P);
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        memset(t, -1, sizeof(t));
        return solve(1, 1, n);
    }
};