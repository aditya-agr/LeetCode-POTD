class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows == 1)
            return res;
        res.push_back({1,1});
        
        for(int i=0; i<numRows-2; i++){
            vector<int> curr = res.back();
            int n = curr.size();
            for(int j=n-1; j>0; j--)
                curr[j] += curr[j-1];
            curr.push_back(1);
            res.push_back(curr);
        }
        return res;

    }
};