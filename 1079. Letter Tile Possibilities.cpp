class Solution {
public:
    vector<bool> vis;
    unordered_set<string> st;
    int n;
    void solve(string s, string &res){
        st.insert(res);
        for(int i=0; i<n; i++){
            if(vis[i]) continue; 
            vis[i] = true;
            res.push_back(s[i]);
            solve(s, res);
            res.pop_back();
            vis[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vis.resize(n, false);
        string res;
        solve(tiles, res);
        return st.size()-1;
    }
};