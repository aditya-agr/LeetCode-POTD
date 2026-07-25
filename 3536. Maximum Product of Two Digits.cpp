class Solution {
public:
    int maxProduct(int n) {
        vector<int> digit(10);
        while(n){
            int rem = n%10;
            digit[rem]++;
            n /= 10;
        }
        int f = 0, s = 0;
        for(int i=9; i>=0; i--){
            if(digit[i] > 0){
                f = i;
                digit[i]--;
                break;
            }
        }
        for(int i=9; i>=0; i--){
            if(digit[i] > 0){
                s = i;
                digit[i]--;
                break;
            }
        }
        return f*s;
    }
};