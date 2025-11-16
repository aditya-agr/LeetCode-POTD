class Solution {
public:
    int numSub(string s) {
        int res = 0, cnt = 0;
        int mod = 1e9+7;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '1')
                cnt++;
            else
                cnt = 0;
            res = (res%mod + cnt%mod)%mod;
        }
        return res;
    }
};