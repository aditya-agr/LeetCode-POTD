class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int res = 0;
        for(int x : nums){
            while(!st.empty() && x < st.top()){
                if(st.top() != 0)
                    res += 1;
                st.pop();
            }
            while(!st.empty() && x == st.top()){
                st.pop();
            }
            st.push(x);
        }
        while(!st.empty()){
            if(st.top() != 0)
                res++;
            st.pop();
        }
        return res;
    }
};