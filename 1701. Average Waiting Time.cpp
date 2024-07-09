class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totwait = 0;
        int currtime = 0;

        for(auto &x : customers){
            int atime = x[0];
            int ptime = x[1];
            currtime = max(currtime, atime);
            currtime += ptime;
            totwait += (currtime - atime);
        }
        return totwait/customers.size();
    }
};