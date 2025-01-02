class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> idx(n);
        for(int i=0; i<n; i++){
            int len = words[i].length();
            bool stvowel = false, edvowel = false;
            for(char c : vowels){
                if(c == words[i][0])
                    stvowel = true;
                if(c == words[i][len-1])
                    edvowel = true;
            }
            idx[i] = (stvowel && edvowel);
        }
        for(int i=1; i<n; i++)
            idx[i] += idx[i-1];

        vector<int> res;
        for(vector<int> q : queries){
            int st = q[0]-1;
            int ed = q[1];
            if(st == -1)
                res.push_back(idx[ed]);
            else
                res.push_back(idx[ed] - idx[st]);
        }
        return res;
    }
};