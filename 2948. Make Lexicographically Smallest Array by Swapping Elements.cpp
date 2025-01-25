class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> idx = nums;
        sort(idx.begin(), idx.end());
        unordered_map<int, int> mp;
        vector<list<int>> vec;
        list<int> q;
        vec.push_back(q);
        int n = nums.size();
        int grp = 0;
        for(int i=0; i<n-1; i++){
            mp[idx[i]] = grp; 
            vec.back().push_back(idx[i]);
            if(idx[i+1]-idx[i] > limit){
                list<int> q;
                vec.push_back(q);
                grp++;
            }
        }
        mp[idx[n-1]] = grp;
        vec.back().push_back(idx[n-1]);

        for(int i=0; i<n; i++){
            int g = mp[nums[i]];
            nums[i] = *(vec[g].begin());
            vec[g].pop_front();
        }
        return nums;
    }
};