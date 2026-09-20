class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            char c = s[i];
            res += (26 - (c-'a'))*(i+1);
        }
        return res;
    }
};