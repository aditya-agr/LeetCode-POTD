class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        int n = folder.size();
        for(int i=1; i<n; i++){
            string curr = folder[i];
            string last = res.back()+'/';
            if(curr.find(last) != 0)
                res.push_back(curr);
        }
        return res;
    }
};