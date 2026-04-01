#define pp pair<int,int>
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pp> vec(n);
        for(int i=0; i<n; i++)
            vec[i] = {positions[i], i};
        sort(vec.begin(), vec.end());
        vector<int> res(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            int p = vec[i].first;
            int idx = vec[i].second;
            int h = healths[idx];
            char d = directions[idx];
            if(d == 'L'){
                while(!st.empty() && h>healths[st.top()]){
                    st.pop();
                    h--;
                }
                if(!st.empty() && healths[st.top()]>h)
                    healths[st.top()] -= 1;
                else if(!st.empty() && healths[st.top()] == h)
                    st.pop();
                else if(st.empty())
                    res[idx] = h;
            }
            else
                st.push(idx);
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            res[idx] = healths[idx];
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(res[i] > 0)
                ans.push_back(res[i]);
        }
        return ans;
    }
};