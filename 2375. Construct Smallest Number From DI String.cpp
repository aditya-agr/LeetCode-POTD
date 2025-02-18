class Solution {
public:
    string smallestNumber(string pattern) {
        string res = "";
        int n = pattern.size();
        stack<char> st;
        for(int i=0; i<=n; i++){
            st.push('0'+i+1);
            if(i==n || pattern[i] == 'I'){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
            }
        }
        return res;
    }
};