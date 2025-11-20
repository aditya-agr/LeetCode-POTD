class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto comp = [](vector<int> &a, vector<int> &b){
            if(a[1] < b[1])
                return true;
            if(a[1] > b[1])
                return false;
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 2, f = intervals[0][1]-1, s = intervals[0][1];
        int n = intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i][0] > s){
                cnt += 2;
                f = intervals[i][1]-1;
                s = intervals[i][1];
            }
            else if(intervals[i][0] <= f)
                continue;
            else{
                cnt += 1;
                if(s == intervals[i][1])
                    f = intervals[i][1]-1;
                else{
                    f = s;
                    s = intervals[i][1];
                }
            }
        }
        return cnt;
    }
};