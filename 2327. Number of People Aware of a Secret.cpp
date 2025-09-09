class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> idx(n);
        idx[0] = 1;
        int m = 1e9+7;
        for(int i=0; i<n; i++)
            for(int j=i+delay; j<i+forget && j<n; j++)
                idx[j] = (idx[j]%m+idx[i]%m)%m;
        long long ans = 0;
        for(int i=n-1; i>=n-forget; i--)
            ans = (ans%m+idx[i]%m)%m;
        return ans;
    }
};