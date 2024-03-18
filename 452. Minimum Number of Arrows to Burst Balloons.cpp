class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comp = [&](vector<int>a, vector<int>b)->bool{
            return a[0]<b[0];
        };
        sort(points.begin(), points.end(), comp);
        int arrows=1;
        int end = points[0][1];
        for(auto i : points){
            if (i[0] > end) {
                arrows++;
                end = i[1];
            }
            else 
                end = min(end, i[1]);
        }
        return arrows;


    }
};