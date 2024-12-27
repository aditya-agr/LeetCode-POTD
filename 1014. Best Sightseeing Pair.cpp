class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = values[0]+0;
        int n = values.size();
        int res = 0;
        for(int i=1; i<n; i++){
            int curr = values[i]-i;
            curr += mx;
            res = max(res, curr);
            mx = max(mx, values[i]+i);
        }
        return res;
    }
};