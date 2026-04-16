#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        pmr::unordered_map<int, vector<int>> mp(&pool);
        mp.reserve(n);
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int m = queries.size();
        vector<int> res(m, -1);
        for(int i=0; i<m; i++){
            if(mp[nums[queries[i]]].size() == 1)
                continue;
            else{
                vector<int> &cur = mp[nums[queries[i]]];
                int sz = cur.size();
                int p = queries[i];
                int idx = lower_bound(cur.begin(), cur.end(), p)-cur.begin();
                int pidx = (idx == 0) ? cur[sz-1] : cur[idx-1];
                int nidx = (idx == sz-1) ? cur[0] : cur[idx+1];
                int ans = min((p-pidx+n)%n, (nidx-p+n)%n);
                res[i] = ans;
            }
        }
        return res;
    }
};