class Solution {
public:
    int search(vector<vector<int>>& items, int q){
        int n = items.size();
        int l = 0, h = n-1;
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(items[mid][0] <= q){
                l = mid+1;
                ans = items[mid][1];
            }
            else
                h = mid-1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int mxB = 0;
        for(auto &x : items){
            mxB = max(mxB, x[1]);
            x[1] = mxB;
        }

        int n = queries.size();
        vector<int> res(n);
        for(int i=0; i<n; i++)
            res[i] = search(items, queries[i]);

        return res;
    }
};