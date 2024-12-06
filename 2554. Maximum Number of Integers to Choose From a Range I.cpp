class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(int x : banned)
            st.insert(x);
        long long sum = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(st.find(i) == st.end()){
                sum += i;
                cnt++;
            }
            if(sum > maxSum)
                return cnt-1;
        }
        return cnt;
    }
};

