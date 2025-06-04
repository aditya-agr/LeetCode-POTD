class Solution {
public:
    string answerString(string word, int numFriends) {
        string res = "";
        int n = word.length();
        if(numFriends == 1)
            return word;
        int longest = n-numFriends+1;
        for(int i=0; i<n; i++){
            int len = min(longest, n-i);
            res = max(res, word.substr(i, len));
        }
        return res;
    }
};