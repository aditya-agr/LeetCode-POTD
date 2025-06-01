class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(n > limit*3)
            return 0;
        if(n == limit*3)
            return 1;

        long long ways = 0;
        int mn = max(0, n - 2*limit);
        int mx = min(n, limit);
        for(int i=mn; i<=mx; i++){
            int N = n-i;
            int mn2 = max(0, N-limit);
            int mx2 = min(N, limit);
            ways += mx2 - mn2 + 1;
        }
        return ways;

    }
};