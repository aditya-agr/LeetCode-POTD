class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = -1;
        int n = arr.size(), cnt = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, arr[i]);
            if(mx == i)
                cnt++;
        }
        return cnt;
    }
};