class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> idx(26);
        int n = word.size();
        for(int i=0; i<n; i++)
            idx[word[i]-'a']++;
        
        sort(idx.begin(), idx.end());
        vector<int> pre(26);
        pre[0] = idx[0];
        for(int i=1; i<26; i++)
            pre[i] = pre[i-1]+idx[i];

        int res = INT_MAX, prev = 0;
        for(int i=0; i<26; i++){
            if(i > 0)
                prev = pre[i-1];
            int pos = upper_bound(idx.begin(), idx.end(), idx[i]+k) - idx.begin();
            int total = pre[25] - pre[pos-1];
            int allowed = (26-pos)*(idx[i]+k);
            res = min(res, prev+total-allowed);
        }
        return res;
    }
};