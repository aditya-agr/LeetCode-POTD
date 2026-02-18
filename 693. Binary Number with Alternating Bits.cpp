class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n%2;
        while(n){
            if(n%2 != flag)
                return false;
            n /= 2;
            flag = 1-flag;
        }
        return true;
    }
};