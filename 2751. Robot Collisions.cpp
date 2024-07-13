class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for(int i=0; i<n; i++)
            idx[i] = i;
        auto comp = [&](int i ,int j){
            return positions[i]<positions[j];
        };
        sort(idx.begin(), idx.end(), comp);
        stack<int> st;
        for(int i=0; i<n; i++){
            int x = idx[i];
            if(directions[x]=='R')
                st.push(x);
            else{
                while(!st.empty() && healths[x]>0){
                    int tp = st.top();
                    st.pop();
                    if(healths[tp] > healths[x]){
                        healths[x] = 0;
                        healths[tp]--;
                        st.push(tp);
                    }
                    else if(healths[tp] < healths[x]){
                        healths[x]--;
                        healths[tp] = 0;
                    }
                    else{
                        healths[x] = 0;
                        healths[tp] = 0;
                    }
                }
            }
        }
        vector<int> res;
        for(int & i : healths)
            if(i>0)
                res.push_back(i);
        return res;
    }
};