class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int cnt = 0;
        vector<int> resolved(n);
        for(int j=0; j<m; j++){
            bool flag = true;
            for(int i=1; i<n; i++){
                if(!resolved[i] && strs[i][j] < strs[i-1][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                cnt++;
                continue;
            }
            for(int i=1; i<n; i++){
                if(strs[i][j] > strs[i-1][j])
                    resolved[i] = 1;
            }

        }

        return cnt;
    }
};