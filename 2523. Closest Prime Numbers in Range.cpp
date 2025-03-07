class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(!prime[i]) continue;
            for(int j=i*i; j<=n; j+=i)
                prime[j] = false;
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left<=2 && right>=3)
            return {2,3};
        vector<bool> primes = sieve(right+2);
        vector<int> prime;
        for(int i=left; i<=right; i++)
            if(primes[i])
                prime.push_back(i);

        int n = prime.size();
        int minDiff = INT_MAX;
        vector<int> res(2, -1);
        for(int i=1; i<n; i++){
            cout<<prime[i];
            if(prime[i]-prime[i-1] < minDiff){
                minDiff = prime[i]-prime[i-1];
                res[0] = prime[i-1];
                res[1] = prime[i];
            }
        }
        return res;
    }
};