class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> a, b;
        int n = img1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1)
                    a.push_back({i, j});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }
        int o = a.size();
        int p = b.size();
        map<pair<int, int>, int> mp;
        int res = 0;
        for(int i=0; i<o; i++){
            for(int j=0; j<p; j++){
                int dx = a[i].first - b[j].first;
                int dy = a[i].second - b[j].second;
                mp[{dx, dy}] += 1;
                res = max(res, mp[{dx, dy}]);
            }
        }
        return res;
    }
};