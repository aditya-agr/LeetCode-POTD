class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> st;
        vector<int> res(n, -1);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int x = rains[i];
            if(x == 0){
                st.insert(i);
                res[i] = 1;
                continue;
            }
            if(mp[x] > 0){
                if(!st.empty() && st.lower_bound(mp[x]) != st.end()){
                    int idx = *st.lower_bound(mp[x]);
                    res[idx] = rains[mp[x]-1];
                    st.erase(idx);
                    mp[x] = i+1;
                }
                else
                    return {};
            }
            else
                mp[x] = i+1;
        }
        return res;
    }
};