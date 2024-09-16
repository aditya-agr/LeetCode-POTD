class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time;
        for(string s : timePoints){
            string hh = s.substr(0, 2);
            string mm = s.substr(3);
            int hrs = stoi(hh);
            int mins = stoi(mm);
            time.push_back(hrs*60 + mins);
        }
        sort(time.begin(), time.end());
        int ans=INT_MAX;
        for(int i=1; i<n; i++)
            ans = min(ans, time[i]-time[i-1]);
        return min(ans, 24*60-(time[n-1]-time[0]));
    }
};