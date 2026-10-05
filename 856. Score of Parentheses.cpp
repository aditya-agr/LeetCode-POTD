class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(char c : s){
            if(c == '(')
                st.push(-1);
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int res = 0;
                    while(st.top() != -1){
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(res*2);
                }
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};