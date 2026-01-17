class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2 = min(topRight[j][0], topRight[i][0]);
                int y2 = min(topRight[j][1], topRight[i][1]);
                int w = x2-x1;
                int h = y2-y1;
                if(w<0 || h<0)
                    continue;
                long long a = 1LL*min(w, h)*min(w, h);
                res = max(res, a);
            }
        }
        return res;
    }
};