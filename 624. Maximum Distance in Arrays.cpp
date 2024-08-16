class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn=1e5;
        int mx=-1e5;
        int res=0;
        for(auto &i : arrays){
            int tmp = max(mx-i[0], i.back()-mn);
            res = max(res, tmp);
            mn = min(mn, i[0]);
            mx = max(mx, i.back());
        }
        return res;
    }
};