class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();
        for(int i=0; i<=n-k; i++){
            string sub = s.substr(i, k);
            st.insert(sub);
        }
        int m = st.size();
        return (m == pow(2,k));
    }
};