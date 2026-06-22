class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> f(26);
        for(char &c : text)
            f[c-'a']++;

        int res = INT_MAX;
        res = min(res, f['b'-'a']);
        res = min(res, f['a'-'a']);
        res = min(res, f['l'-'a']/2);
        res = min(res, f['o'-'a']/2);
        res = min(res, f['n'-'a']);
        return res;
    }
};