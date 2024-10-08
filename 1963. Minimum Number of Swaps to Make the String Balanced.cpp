class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char c : s){
            if(!st.empty() && c==']')
                st.pop();
            if(c=='[')
                st.push('[');
        }
        return (st.size()+1)/2;
    }
};