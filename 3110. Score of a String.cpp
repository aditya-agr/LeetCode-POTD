class Solution {
public:
    int scoreOfString(string s) {
        int score=0, n=s.length();
        for(int i=0; i<n-1; i++)
            score += abs(s[i]-s[i+1]);
        return score;
    }
};