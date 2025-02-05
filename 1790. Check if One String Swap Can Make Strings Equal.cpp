class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        vector<int> idx;
        int n = s1.size();
        for(int i=0; i<n; i++)
            if(s1[i] != s2[i])
                idx.push_back(i);

        if(idx.size()==2)
            swap(s1[idx[0]], s1[idx[1]]);
        
        return s1 == s2;
    }
};