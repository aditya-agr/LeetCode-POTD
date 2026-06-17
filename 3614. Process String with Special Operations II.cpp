class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long len = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '*')
                len = max(len-1, 0LL);
            else if(s[i] == '#')
                len *= 2;
            else if(s[i] == '%')
                len = len;
            else
                len++;
        }
        if(k >= len)
            return '.';

        for(int i=n-1; i>=0; i--){
            if(s[i] == '*')
                len++;
            else if(s[i] == '#'){
                if(k >= len/2)
                    k -= len/2;
                len /= 2;
            }
            else if(s[i] == '%')
                k = len-1-k;
            else{
                if(len == k+1)
                    return s[i];
                len--;
            }
        }
        return '.';
    }
};