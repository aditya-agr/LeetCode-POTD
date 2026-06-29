class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        int n = patterns.size();
        int m = word.size();
        for(int i=0; i<n; i++){
            int s = patterns[i].size();
            int x=0, y=0;
            for(int j=0; j<m; j++){
                if(word[j] == patterns[i][0]){
                    int k=0, p=j;
                    while(p<m && k<s  && word[p]==patterns[i][k]){
                        p++;
                        k++;
                    }
                    if(k == s){
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};