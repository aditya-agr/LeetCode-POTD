class Solution {
public:
    int minOperations(string s) {
        int op = 0, cur = 0;
        int n = s.length();
        for(char c : s){
            if((c-'0') != cur)
                op++;
            cur = 1-cur;
        }
        return min(op, n-op);
    }
};