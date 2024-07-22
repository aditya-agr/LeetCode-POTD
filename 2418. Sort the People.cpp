class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // unordered_map<int, string> mp;
        // int n = names.size();
        // for(int i=0; i<n; i++)
        //     mp[heights[i]] = names[i];
        
        // sort(heights.begin(), heights.end(), greater<int>());
        // for(int i=0; i<n; i++)
        //     names[i] = mp[heights[i]];
        // return names;

        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        auto comp = [&](int a, int b){
            return heights[a] > heights[b];
        };
        sort(idx.begin(), idx.end(), comp);
        vector<string> res(n);
        for(int i=0; i<n; i++)
            res[i] = names[idx[i]];
        return res;
    }
};