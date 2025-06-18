class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        for(int i=0; i<n; i++){
            cur.push_back(nums[i]);
            if(cur.size() == 3){
                if(cur[2]-cur[0] > k)
                    return {};
                res.push_back(cur);
                cur.clear();
            }
        }
        return res;
    }
};