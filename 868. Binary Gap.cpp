class Solution {
public:
    int binaryGap(int n) {
        int res = 0, prev = n;
        for(int i=0; i<32; i++){
            int rem = (n>>i)&1;
            if(rem){
                res = max(res, i-prev);
                prev = i;
            }
        }
        return res;
    }
};