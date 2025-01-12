class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2)
            return false;
        stack<int> st, st1;
        int i=0;
        while(i<n){
            if(locked[i] == '1'){
                if(s[i] == '(')
                    st.push(i);
                else{
                    if(st.empty())
                        return false;
                    st.pop();
                }
            }
            else
                st.push(i);
            i++;
        }

        i=n-1;
        while(i>=0){
            if(locked[i]=='1'){
                if(s[i]==')')
                    st1.push(i);
                else{
                    if(st1.empty())
                        return false;
                    st1.pop();
                }
            }
            else
                st1.push(i);
            i--;
        }
        return true;
    }
};