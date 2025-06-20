class Solution {
public:
    int maxDistance(string s, int k) {
        int ver=0, hor=0;
        int res = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == 'N')
                ver++;
            else if(s[i] == 'S')
                ver--;
            else if(s[i] == 'E')
                hor++;
            else
                hor--;
            int cur = min(i+1, abs(ver)+abs(hor)+k*2);
            res = max(res, cur);
        }
        return res;
    }
};