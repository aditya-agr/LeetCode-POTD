class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c : s){
            if(c != ')')
                st.push(c);
            else{
                queue<char> q;
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};