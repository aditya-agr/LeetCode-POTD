class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9+7;
        unordered_set<int> st;
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        int h = hFences.size();
        for(int i=0; i<h; i++){
            for(int j=i+1; j<h; j++){
                st.insert(hFences[j]-hFences[i]);
            }
        }
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());
        int v = vFences.size();
        long long res = -1;
        for(int i=0; i<v; i++){
            for(int j=i+1; j<v; j++){
                int d = vFences[j]-vFences[i];
                if(st.count(d))
                    res = max(res, 1LL*d*d);
            }
        }
        return res%mod;
    }
};