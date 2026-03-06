class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1])
                cnt++;
            if(cnt == 2)
                return false;
        }
        return true;
    }
};