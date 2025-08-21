class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            vector<int> cur(m, 1);
            for(int j=i; j<n; j++){
                for(int k=0; k<m; k++)
                    cur[k] = cur[k]&mat[j][k];

                int t = 0;    
                for(int k=0; k<m; k++){
                    if(cur[k] == 0)
                        t = 0;
                    else
                        t++;
                    cnt += t;
                }
            }
        }
        return cnt;
    }
};