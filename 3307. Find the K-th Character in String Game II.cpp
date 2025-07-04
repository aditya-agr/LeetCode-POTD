class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1, it = 0;
        while(len<k){
            len *= 2;
            it++;
        }
        int cnt = 0;
        while(k>1){
            if(k > len/2 && operations[it-1]==1)
                cnt++;
            if(k > len/2)
                k -= (1ll<<(it-1));
            len /= 2;
            it--;
        }
        return 'a'+cnt%26;
    }
};