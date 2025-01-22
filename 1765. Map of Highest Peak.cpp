class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir = {{0,-1}, {0,1}, {1,0}, {-1, 0}};
        int h = 1;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(vector<int> x : dir){
                    int i_ = i+x[0];
                    int j_ = j+x[1];
                    if(i_>=0 && i_<n && j_>=0 && j_<m && res[i_][j_]==-1){
                        res[i_][j_] = h;
                        q.push({i_, j_});
                    }
                }
            }
            h++;
        }
        return res;
    }
};