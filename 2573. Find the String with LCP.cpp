class Solution {
public:
    vector<vector<int>> checkLCP(string &s){
        int n = s.length();
        vector<vector<int>> res(n, vector<int>(n));
        for(int i=0; i<n; i++){
            if(s[i] == s[n-1]){
                res[i][n-1] = 1;
                res[n-1][i] = 1;
            }
        }
        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(s[i] == s[j])
                    res[i][j] = 1+res[i+1][j+1];
            }
        }
        return res;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '$');
        for(int i=0; i<n; i++){
            vector<bool> isValid(26, true);
            for(int j=0; j<i; j++){
                if(lcp[j][i] != 0){
                    s[i] = s[j];
                    break;
                }
                else
                    isValid[s[j]-'a'] = false;
            }
            if(s[i] == '$'){
                for(int x=0; x<26; x++){
                    if(isValid[x]){
                        s[i] = x+'a';
                        break;
                    }
                }
                if(s[i] == '$')
                    return "";
            }
        }
        return checkLCP(s) == lcp ? s : "";
    }
};