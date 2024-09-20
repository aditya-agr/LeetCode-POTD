class Solution {
public:
    int kmp(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s+"#"+rev;
        int n=str.length();
        vector<int> lps(n);
        int i=0, j=1;
        while(j<n){
            if(str[i]==str[j]){
                i++;
                lps[j] = i;
                j++;
            }
            else{
                if(i>0)
                    i=lps[i-1];
                else
                    j++;
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        int cnt = kmp(s);
        string tmp = s.substr(cnt);
        reverse(tmp.begin(), tmp.end());
        return tmp+s;
    }
};