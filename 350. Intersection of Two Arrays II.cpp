class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for(int i: nums1)
            m1[i]++;
        for(int i: nums2)
            m2[i]++;
        vector<int> res;
        for(auto i : m1){
            int n = i.first;
            if(m2[n]){
                int mn = min(i.second, m2[n]);
                while(mn--)
                    res.push_back(n);
            }
        }
        return res;
    }
};