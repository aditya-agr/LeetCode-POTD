class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> cnta(n), cntb(n);
        cnta[0] = (s[0]=='a') ? 1 : 0;
        for(int i=1; i<n; i++){
            cnta[i] = (s[i] == 'a') ? 1 : 0;
            cnta[i] += cnta[i-1];
        }
        cntb[n-1] = (s[n-1]=='b') ? 1 : 0;
        for(int i=n-2; i>=0; i--){
            cntb[i] = (s[i] == 'b') ? 1 : 0;
            cntb[i] += cntb[i+1];
        }
        int res = n;
        for(int i=0; i<n; i++){
            int cur = cnta[i]+cntb[i];
            res = min(res, n-cur);
        }
        return res;
    }
};