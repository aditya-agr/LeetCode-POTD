class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto comp = [](vector<int>&a, vector<int> &b){
            if(a[0] == b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int res=0, x=-1, y=-1;
        for(int i=0; i<n; i++){
            if(intervals[i][0]>=x && intervals[i][1]<=y)
                continue;
            else{
                res++;
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        return res;
    }
};