class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        int a = newInterval[0];
        int b = newInterval[1];
        while (i < n && intervals[i][1] < a) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= b) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};