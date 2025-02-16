class Solution {
public:
    bool solve(vector<int> &idx, vector<int> &vis, int n, int i){
        while(i<idx.size() && idx[i]!=0)
            i++;
        if(i == idx.size())
            return true;
        for(int x=n; x>0; x--){
            if(vis[x]) continue;
            if(x==1){
                idx[i] = x;
                vis[x] = 1;
                if(solve(idx, vis, n, i+1))
                    return true;
                vis[x] = 0;
                idx[i] = 0;
            }
            else if(i+x<idx.size() && idx[i+x]==0){
                idx[i] = x;
                idx[i+x] = x;
                vis[x] = 1;
                if(solve(idx, vis, n, i+1))
                    return true;
                vis[x] = 0;
                idx[i] = 0;
                idx[i+x] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int sz = n*2-1;
        vector<int> idx(sz);
        vector<int> vis(n+1);
        solve(idx, vis, n, 0);
        return idx;
    }

};