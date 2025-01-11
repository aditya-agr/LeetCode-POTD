class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k)
            return false;
        vector<int> idx(26);
        for(char c : s)
            idx[c-'a']++;
        int cnt=0;
        for(int i=0; i<26; i++)
            if(idx[i]%2)
                cnt++;
        return cnt <= k;
    }
};