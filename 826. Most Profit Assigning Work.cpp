class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++)
            vec.push_back({profit[i], difficulty[i]});

        sort(vec.rbegin(), vec.rend());
        sort(worker.rbegin(), worker.rend());
        int res=0, j=0;
        for(int i=0; i<m; i++){
            while(j<n && worker[i]<vec[j].second)
                j++;
            if(j<n) res += vec[j].first;
        }
        return res;
    }
};