class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0, r=sqrt(c);
        while(l<=r){
            long long nc = l*l + r*r;
            if(nc==c)
                return true;
            else if(nc<c)
                l++;
            else
                r--;
        }
        return false;
    }
};