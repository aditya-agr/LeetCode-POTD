class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cntOdd = 0, cntEven = 1;
        int n = arr.size();
        int sum = 0, res = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum%2){
                cntOdd = (cntOdd+1)%mod;
                res = (res+cntEven)%mod;
            }
            else{
                cntEven = (cntEven+1)%mod;
                res = (res+cntOdd)%mod;
            }
        }
        return res;
    }
};