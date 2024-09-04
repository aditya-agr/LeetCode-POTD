class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> st;
        for(auto it : obstacles)
            st.insert(it);
        int dir=0;
        unordered_map<int, pair<int, int>> mp;
        mp[0] = {0, 1};
        mp[1] = {1, 0};
        mp[2] = {0, -1};
        mp[3] = {-1, 0};

        int ans=0, x=0, y=0; 
        for(auto c : commands){
            if(c==-1)
                dir = (dir+1)%4;
            else if(c==-2)
                dir = (dir-1+4)%4;
            else{
                while(c--){
                    int nx = x + mp[dir].first;
                    int ny = y + mp[dir].second;
                    vector<int> tmp = {nx, ny};
                    if(st.count(tmp)>0)
                        break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x+y*y);
                }
            }
        }
        return ans;
    }
};