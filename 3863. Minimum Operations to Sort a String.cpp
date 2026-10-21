class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string t = s;
        sort(t.begin(), t.end());
        vector<int> dp(26);
        for(char c : s)
            dp[c-'a']++;
        
        if(s == t)
            return 0;
        if(n==2 && s[0]!=t[0] && s[n-1]!=t[n-1])
            return -1;
        if(s[0]==t[0] || s[n-1]==t[n-1])
            return 1;
        else if(s[0]==t[n-1] && s[n-1]==t[0] && dp[s[0]-'a']==1 && dp[s[n-1]-'a']==1)
            return 3;
        else
            return 2;
    }
};