class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> idx(n);
        idx[0] = arr[0];
        for(int i=1; i<n; i++)
            idx[i] = idx[i-1]^arr[i];
        vector<int> res;
        for(auto x : queries){
            int l = x[0];
            int r = x[1];
            if(l==0)
                res.push_back(idx[r]);
            else
                res.push_back(idx[l-1]^idx[r]);
        }
        return res;
    }
};