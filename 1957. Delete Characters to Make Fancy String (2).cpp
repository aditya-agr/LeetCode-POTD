class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n<3)
            return s;
        string fancy_s= s.substr(0,2);
        for(int i=2; i<n; i++){
            if(s[i]==s[i-1] && s[i]==s[i-2])
                continue;
            fancy_s += s[i];
        }
        return fancy_s;
    }
};