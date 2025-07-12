class Solution {
public:
    int f, s, N;
    int mn = INT_MAX, mx = INT_MIN;
    void solve(int mask, int round, int i, int j){
        while(i<j && (mask&(1<<i)) == 0)
            i++;
        while(i<j && (mask&(1<<j)) == 0)
            j--;
        if(i>=j){
            solve(mask, round+1, 0, N);
            return;
        }
        if(i==f && j==s){
            mn = min(mn, round);
            mx = max(mx, round);
        }
        else{
            if(i!=f && i!=s)
                solve(mask^(1<<i), round, i+1, j-1);
            if(j!=f && j!=s)
                solve(mask^(1<<j), round, i+1, j-1);
        }

    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n-1;
        f = firstPlayer-1;
        s = secondPlayer-1;
        solve((1<<n)-1, 1, 0, n-1);
        return {mn, mx};
    }
};