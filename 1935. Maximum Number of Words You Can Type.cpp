class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> dp(26);
        for(char c : brokenLetters)
            dp[c-'a']++;
        int n = text.length();
        int cnt = 0, i=0;
        while(i<n){
            bool flag = true;
            while(i<n && text[i] != ' '){
                if(dp[text[i]-'a'])
                    flag = false;
                i++;
            }
            cnt += flag;
            i++;
        }
        return cnt;
    }
};