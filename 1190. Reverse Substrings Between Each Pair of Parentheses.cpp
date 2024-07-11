class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto &ch : s){
            if(ch==')'){
                string str="";
                while(st.top()!='('){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for(char &c : str)
                    st.push(c);
            }
            else
                st.push(ch);
        }
        string res="";
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};