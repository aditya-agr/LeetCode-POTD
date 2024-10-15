class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0;
        int n = s.length();
        int cnt0=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0') cnt0++;
            else res+=cnt0;
        }
        return res;
    }
};