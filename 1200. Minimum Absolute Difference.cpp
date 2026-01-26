class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mn = INT_MAX;
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            int diff = arr[i+1]-arr[i];
            if(mn > diff)
                mn = diff;
        }
        vector<vector<int>> res;
        for(int i=0; i<n-1; i++){
            int diff = arr[i+1]-arr[i];
            if(diff == mn)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};