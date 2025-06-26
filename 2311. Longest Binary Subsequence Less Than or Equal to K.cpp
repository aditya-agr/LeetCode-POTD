class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int len = 0;
        int power = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0')
                len++;
            else if(power <= k){
                k -= power;
                len++;
            }
            if(power<= k)
                power *= 2;
        }
        return len;
    }
};