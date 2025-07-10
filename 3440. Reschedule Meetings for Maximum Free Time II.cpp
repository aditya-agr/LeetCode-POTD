class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free;
        int n = startTime.size();
        free.push_back(startTime[0]);
        for(int i=1; i<n; i++)
            free.push_back(startTime[i]-endTime[i-1]);
        free.push_back(eventTime - endTime[n-1]);

        int m = free.size();
        vector<int> right(m);
        for(int i=m-2; i>=0; i--)
            right[i] = max(right[i+1], free[i+1]);
        int left = 0;
        int res = 0;
        for(int i=1; i<m; i++){
            int d = endTime[i-1] - startTime[i-1];
            if(right[i]>=d || left>=d)
                res = max(res, d+free[i]+free[i-1]);
            else
                res = max(res, free[i]+free[i-1]);
            left = max(left, free[i-1]);
        }
        return res;


    }
};