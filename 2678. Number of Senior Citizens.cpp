class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string s: details){
            if(s[11]>'6' || (s[11]=='6' && s[12]>'0'))
                cnt++;
        }
        return cnt;
    }
};