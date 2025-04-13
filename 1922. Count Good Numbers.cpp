class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long x, long long n){
        if(n==0)
            return 1;
        long long half = power(x, n/2);
        long long res = (half*half)%mod;
        if(n%2)
            res = (res*x)%mod;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2, odd = n/2;
        long long res = power(5, even)%mod;
        res = (res * power(4, odd))%mod;
        return res;
    }
};