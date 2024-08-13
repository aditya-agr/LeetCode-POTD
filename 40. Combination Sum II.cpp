class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx, vector<vector<int>> &res, vector<int> &curr){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(curr);
            return;
        }
        int n = candidates.size();
        for(int i=idx; i<n; i++){
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, res, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates, target, 0, res, curr);
        return res;
    }
};