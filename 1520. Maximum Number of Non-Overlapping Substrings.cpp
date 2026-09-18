class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> in(26, vector<int>(2, -1));
        int n = s.size();
        for(int i=0; i<n; i++){
            char c = s[i];
            if(in[c-'a'][0] == -1)
                in[c-'a'][0] = i;
            in[c-'a'][1] = i;
        }
        vector<string> res;
        
        int last = -1;
        for(int i=0; i<n; i++){
            if(i == in[s[i]-'a'][0]){
                int j = in[s[i]-'a'][1];
                for(int x = i; x <= j; x++){
                    if(in[s[x]-'a'][0] < i){
                        j = -1;
                        break;
                    }
                    j = max(j, in[s[x]-'a'][1]);
                }
                if(j != -1){
                    if(i > last)
                        res.push_back(s.substr(i, j-i+1));
                    else
                        res.back() = s.substr(i, j-i+1);
                    last = j;
                }
            }
        }
        return res;
        
    }
};