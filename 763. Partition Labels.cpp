class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> last(26);
        for(int i=0; i<n; i++)
            last[s[i]-'a'] = i;
        
        int i=0, j=0, end=last[s[0]-'a'];
        vector<int> res;
        while(i<n){
            while(j<end){
                end = max(end, last[s[j]-'a']);
                j++;
            }
            res.push_back(j-i+1);
            i = end+1;
            j = i;
            if(j<n) end = last[s[j]-'a'];
        }
        return res;
    }
};