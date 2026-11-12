class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int res = 1;
        int cur = 1;
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1])
                cur++;
            else
                cur = 1;
            res =  max(res, cur);
        }
        cur = 1;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1])
                cur++;
            else
                cur = 1;
            res =  max(res, cur);
        }
        return res;
    }
};