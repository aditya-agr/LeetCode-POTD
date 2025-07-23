class Solution {
public:
    string removestring(string &s, string &t){
        int n = s.length();
        int i=0, j=0;
        while(j<n){
            s[i] = s[j];
            if(i>0 && s[i]==t[1] && s[i-1]==t[0])
                i--;
            else
                i++;
            j++;
        }
        return s.substr(0, i);
    }
    int maximumGain(string s, int x, int y) {
        string maxStr = (x > y) ? "ab" : "ba"; 
        string minStr = (x > y) ? "ba" : "ab"; 

        int n = s.length();
        string temp = removestring(s, maxStr);
        int l = temp.length();
        int res = (n-l)/2 * max(x, y);

        string temp2 = removestring(temp, minStr);
        int l_ = temp2.length();
        res += (l-l_)/2 * min(x, y);

        return res;
    }
};