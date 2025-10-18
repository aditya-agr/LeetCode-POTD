class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<int> st;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int prev = INT_MIN;
        for(int x : nums) {
    
            for(int newNum = max(prev, x - k); newNum <= x + k; newNum++) {
                if(st.empty() || st.find(newNum) == st.end()) {
                    st.insert(newNum);
                    cnt++;
                    prev = newNum;
                    break;
                }
            }
        }
        
        return cnt;
    }
};