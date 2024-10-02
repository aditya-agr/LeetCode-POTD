class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> mp;
        int n = arr.size(), j=1;
        for(int i=0; i<n; i++){
            if(i>0 && tmp[i] != tmp[i-1])
                j++;
            mp[tmp[i]] = j;
        }
        vector<int> res(n);
        for(int i=0; i<n; i++)
            res[i] = mp[arr[i]];
        return res;
    }
};