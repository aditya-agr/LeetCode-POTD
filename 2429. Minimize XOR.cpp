class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int cnt1 = __builtin_popcount(num1);
        if(cnt1==cnt)
            return num1;
        bitset<32> n1(num1), res(0);
        int flag = 0;
        for(int i=31; i>=0; i--){
            if(n1[i] && cnt){
                res.set(i, 1);
                cnt--;
            }
        }
        int i=0;
        while(cnt>0){
            if(!res[i]){
                res.set(i, 1);
                cnt--;
            }
            i++;
        }
        int ans = res.to_ulong();
        return ans;
    }
};