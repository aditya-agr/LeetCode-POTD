class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratio(n);
        for(int i=0; i<n; i++)
            ratio[i] = make_pair((double)wage[i]/quality[i], quality[i]);

        sort(ratio.begin(), ratio.end());
        priority_queue<int> pq;
        int cost = 0;
        for(int i=0; i<k; i++){
            pq.push(ratio[i].second);
            cost += ratio[i].second;
        }
        double mainratio = ratio[k-1].first;
        double result = mainratio*cost;
        for(int j=k; j<n; j++){
            mainratio = ratio[j].first;
            pq.push(ratio[j].second);
            cost += ratio[j].second;
            if(pq.size()>k){
                cost -= pq.top();
                pq.pop();
            }
            result = min(mainratio*cost, result);
        }
        return result;
    }
};