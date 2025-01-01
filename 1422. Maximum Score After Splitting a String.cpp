class Solution {
public:
    int maxScore(string s) {
        int cnt1 = 0, cnt0 = 0, res = 0;
        for(char x : s)
            cnt1 += (x=='1');
        int n = s.length();
        for(int i=0; i<n-1; i++){
            if(s[i]=='1')
                cnt1--;
            else
                cnt0++;
            res = max(res, cnt0+cnt1);
        }
        return res;
    }
};