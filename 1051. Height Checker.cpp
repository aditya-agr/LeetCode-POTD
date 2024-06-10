class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> a = heights;
        sort(a.begin(), a.end());
        int n=a.size(), cnt=0;
        for(int i=0; i<n; i++)
            if(a[i]!=heights[i])
                cnt++;
        return cnt;
    }
};