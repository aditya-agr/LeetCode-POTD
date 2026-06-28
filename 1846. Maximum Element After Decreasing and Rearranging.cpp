class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            res = min(res+1, arr[i]);
        }
        return res;
    }
};