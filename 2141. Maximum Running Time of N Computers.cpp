class Solution {
public:
    bool check(long long time, int &n, vector<int> &bat){
        long long curr = 0;
        for(int x : bat){
            curr += min(1LL*x, time);
            if(curr >= n*time)
                return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        if(m < n)
            return 0;
        long long tot = 0;
        int mn = INT_MAX;
        for(int i=0; i<m; i++){
            tot += batteries[i];
            mn = min(mn, batteries[i]);
        }
        if(m == n)
            return mn;
        
        long long l = 0;
        long long h = tot/n;
        long long ans = 0;
        while(l <= h){
            long long mid = l + (h-l)/2;
            if(check(mid, n, batteries)){
                ans = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return ans;
        
    }
};