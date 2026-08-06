class Solution {
public:
    bool check(int n, int t){
        int prod = 1;
        int num = n;
        while(num){
            int rem = num%10;
            prod *= rem;
            num /= 10;
        }
        if(prod % t)
            return false;
        return true;
    }
    int smallestNumber(int n, int t) {
        int num = n;
        while(!check(num, t))
            num++;
        return num;
    }
};