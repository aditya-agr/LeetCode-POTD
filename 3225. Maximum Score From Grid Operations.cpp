class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> prefix(n+1, vector<long long>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                prefix[i+1][j] = prefix[i][j] + grid[i][j];

        vector<long long> prevSkip(n+1), prevPick(n+1);
        for(int j=1; j<n; j++){
            vector<long long> curSkip(n+1), curPick(n+1);
            for(int cur=0; cur<=n; cur++){
                for(int prev=0; prev<=n; prev++){
                    if(cur > prev){
                        long long score = prefix[cur][j-1] - prefix[prev][j-1];
                        curSkip[cur] = max(curSkip[cur], prevSkip[prev]+score);
                        curPick[cur] = max(curPick[cur], prevSkip[prev]+score);
                    }
                    else{
                        long long score = prefix[prev][j] - prefix[cur][j];
                        curSkip[cur] = max(curSkip[cur], prevPick[prev]);
                        curPick[cur] = max(curPick[cur], prevPick[prev]+score);
                    }
                }
            }
            prevSkip = curSkip;
            prevPick = curPick;
        }
        return *max_element(prevPick.begin(), prevPick.end());
    }
};