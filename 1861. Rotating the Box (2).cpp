class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                res[i][j] = box[j][i];
        
        for(vector<char> &x : res)
            reverse(x.begin(), x.end());
        
        for(int j=0; j<n; j++){
            int space = m-1;
            for(int i=m-1; i>=0; i--){
                if(res[i][j] == '*'){
                    space = i-1;
                    continue;
                }
                if(res[i][j] == '#'){
                    res[i][j] = '.';
                    res[space][j] = '#';
                    space--;
                }
            }
        }
        return res;
    }
};