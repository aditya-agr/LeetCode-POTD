class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.length();
        int cnt=0;
        for(string s : words){
            int n = s.length();
            int i=0, j=0;
            while(i<n && j<m){
                if(s[i] != pref[j])
                    break;
                i++, j++;
            }
            if(j==m)
                cnt++;
        }
        return cnt;
    }
};