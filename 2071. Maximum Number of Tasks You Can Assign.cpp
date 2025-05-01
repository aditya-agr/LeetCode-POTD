class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        multiset<int> st(workers.begin(), workers.begin()+mid);
        int cnt = 0;
        for(int i=mid-1; i>=0; i--){
            int req = tasks[i];
            auto it = prev(st.end());
            if(*it >= req)
                st.erase(it);
            else if(cnt >= pills)
                return false;
            else{
                auto itr = st.lower_bound(req-strength);
                if(itr == st.end())
                    return false;
                else{
                    st.erase(itr);
                    cnt++;
                }
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        int l = 0;
        int h = min(n, m);

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(tasks, workers, pills, strength, mid)){
                res = max(res, mid);
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};