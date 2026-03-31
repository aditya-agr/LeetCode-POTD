class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string res(n+m-1, '#');
        for(int i=0; i<n; i++){
            if(str1[i] == 'T'){
                for(int j=0; j<m; j++){
                    if(res[i+j]!='#' && res[i+j]!=str2[j])
                        return "";
                    res[i+j] = str2[j];
                }
            }
        }
        vector<bool> canChange(n+m-1, false);
        for(int i=0; i<n+m-1; i++){
            if(res[i] == '#'){
                res[i] = 'a';
                canChange[i] = true;
            }
        }
        for(int i=0; i<n; i++){
            if(str1[i] == 'F'){
                string cur = res.substr(i, m);
                if(cur == str2){
                    int idx = -1;
                    for(int j=m-1; j>=0; j--){
                        if(canChange[i+j]){
                            idx = j;
                            break;
                        }
                    }
                    if(idx == -1)
                        return "";
                    res[idx+i]++;
                }
            }
        }
        return res;
    }
};