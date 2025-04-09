class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int x : nums){
            if(x<k)
                return -1;
            st.insert(x);
        }
        int n = st.size();
        if(st.find(k) != st.end())
            n--;
        return n;
    }
};