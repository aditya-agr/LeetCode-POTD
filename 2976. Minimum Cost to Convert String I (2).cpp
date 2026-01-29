class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<int>> res(26, vector<int>(26, 1e9));
        for(int i=0; i<n; i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];
            res[u][v] = min(res[u][v], w);
        }
        for(int i=0; i<26; i++){
            res[i][i] = 0; 
        }
        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    res[i][j] = min(res[i][j], res[i][via]+res[via][j]);
                }
            }
        }
        int m = source.length();
        long long ans = 0;
        for(int i=0; i<m; i++){
            if(source[i] != target[i]){
                int u = source[i]-'a';
                int v = target[i]-'a';
                if(res[u][v] < 1e9)
                    ans += res[u][v];
                else
                    return -1;
            }
        }
        return ans;
    }
};