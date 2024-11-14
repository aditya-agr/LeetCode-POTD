class Solution {
public:
    bool ispossible(int x, vector<int> &quantities, int n){
        for(int quant : quantities)
            n -= (quant + x - 1)/x;
        if(n < 0)
            return false;
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int mx = 0;
        for(int x : quantities)
            mx = max(mx, x);
        int l = 1, h = mx;
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(ispossible(mid, quantities, n)){
                ans = mid;
                h = mid-1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};