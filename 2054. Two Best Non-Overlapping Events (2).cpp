class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        auto comp = [](vector<int>&a, vector<int>&b){
            if(a[1] < b[1])
                return true;
            else if(a[1] > b[1])
                return false;
            else
                return a[0] < b[0];
        };
        sort(events.begin(), events.end(), comp);
        int n = events.size();
        int res = events[0][2];
        vector<int> mx(n);
        mx[0] = events[0][2];
        for(int i=1; i<n; i++){
            int l=0, h=i-1, j=-1;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(events[i][0] <= events[mid][1])
                    h = mid-1;
                else{
                    j = mid;
                    l = mid+1;
                }
            }
            if(j>=0)
                res = max(res, mx[j]+events[i][2]);
            mx[i] = max(mx[i-1], events[i][2]);
        }
        res = max(res, mx[n-1]);
        return res;
    }
};