class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int prev = 0, cnt = 1;
        int n = s.length();

        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                cnt++;
                if(prev >= cnt) 
                    res++;
            }
            else{
                res++;
                prev = cnt;
                cnt = 1;
            }
        }
        return res;
    }
};