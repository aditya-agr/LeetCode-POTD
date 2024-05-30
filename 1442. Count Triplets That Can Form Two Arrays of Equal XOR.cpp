class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1, 0);
        for(int i=1; i<=n; i++)
            pre[i] = pre[i-1]^arr[i-1];
        int cnt=0;
        for(int i=0; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(pre[i]==pre[j])
                    cnt += (j-i-1);
            }
        }
        return cnt;
    }
};