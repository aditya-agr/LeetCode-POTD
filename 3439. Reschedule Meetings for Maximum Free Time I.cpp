class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> free;
        free.push_back(startTime[0]);
        for(int i=1; i<n; i++)
            free.push_back(startTime[i]-endTime[i-1]);
        free.push_back(eventTime - endTime[n-1]);
        int res = 0;
        int sum = 0, i=0, j=0;

        while(j<n+1){
            sum += free[j];
            cout<<sum<<j;
            int len = j-i+1;
            if(i<n+1 && len > k+1){
                sum -= free[i];
                i++;
            }
            res = max(res, sum);
            j++;
        }
        return res;
    }
};