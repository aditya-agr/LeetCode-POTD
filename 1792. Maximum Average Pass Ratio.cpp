#define P pair<double, int>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq;
        int n = classes.size();
        for(int i=0; i<n; i++){
            double pr = (double)classes[i][0]/classes[i][1];
            double npr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = npr - pr;
            pq.push({diff, i});
        }
        while(extraStudents--){
            auto it = pq.top();
            pq.pop();
            double curr = it.first;
            int idx = it.second;
            classes[idx][0]++;
            classes[idx][1]++;
            double pr = (double)classes[idx][0]/classes[idx][1];
            double npr = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double diff = npr - pr;
            pq.push({diff, idx});
        }
        double res = 0.0;
        for(int i=0; i<n; i++)
            res += (double)classes[i][0]/classes[i][1];
        return res/n;
    }
};