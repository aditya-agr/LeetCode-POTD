
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i=0, j=0;
        vector<int> cnt(26);
        int res = 0;
        while(j<n){
            cnt[s[j]-'a']++;
            while(cnt[s[j]-'a'] > 2){
                cnt[s[i]-'a']--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};