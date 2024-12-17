class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26);
        for(char c : s)
            freq[c-'a']++;
            
        string res;
        int i=25;

        while(i>=0){
            if(freq[i]==0){
                i--;
                continue;
            }
            char ch = 'a'+i;
            int fq = min(freq[i], repeatLimit);
            res.append(fq, ch);
            freq[i] -= fq;
            if(freq[i] > 0){
                int j=i-1;
                while(j>=0 && freq[j]==0)
                    j--;
                if(j<0)
                    break;
                res.push_back('a'+j);
                freq[j]--;
            }
        }
        return res;
    }
};