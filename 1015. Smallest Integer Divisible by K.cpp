class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0)
            return -1;
        unordered_set<int> st;
        int num = 1, len = 1;
        while(!st.count(num)){
            st.insert(num);
            if(num%k == 0)
                return len;
            num = num*10 + 1;
            num %= k;
            len++;
        }
        return -1;
    }
};ss