class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cntE = 1, cntO = 0;
        int curr = 0;
        long long res = 0, mod = 1e9+7;
        for(int x : arr){
            curr += x;
            if(curr%2){
                cntO++;
                res = (res+cntE)%mod;
            }
            else{
                cntE++;
                res = (res+cntO)%mod;
            }
        }
        return res;
    }
};