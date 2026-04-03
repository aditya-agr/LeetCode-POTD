class Solution {
public:
    vector<pair<int,int>> roboDist;
    vector<pair<int,int>> range;
    vector<int> wall;
    vector<vector<int>> dp;
    int n;
    int count(int left, int right){
        int l = lower_bound(wall.begin(), wall.end(), left) - wall.begin();
        int r = upper_bound(wall.begin(), wall.end(), right) - wall.begin();
        return r-l;
    }
    int solve(int i, int dir){
        if(i == n)
            return 0;
        if(dp[i][dir] != -1)
            return dp[i][dir];
        int left =  range[i].first;
        if(dir == 1)
            left = max(left, range[i-1].second+1);
        int l = count(left, roboDist[i].first) + solve(i+1, 0);
        int r = count(roboDist[i].first, range[i].second) + solve(i+1, 1);
        return dp[i][dir] = max(l, r);

    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        int m = walls.size();

        for(int i=0; i<n; i++){
            roboDist.push_back({robots[i], distance[i]});
        }
        sort(roboDist.begin(), roboDist.end());
        sort(walls.begin(), walls.end());
        wall = walls;
        dp.resize(n, vector<int>(2,-1));

        range.resize(n);
        for(int i=0; i<n; i++){
            int left = roboDist[i].first - roboDist[i].second;
            int right = roboDist[i].first + roboDist[i].second;
            int l = (i==0) ? 1 : roboDist[i-1].first + 1;
            int r = (i==n-1) ? 1e9 : roboDist[i+1].first - 1;
            range[i].first = max(left, l);
            range[i].second = min(right, r);
        }
        return solve(0, 0);
    }
};