class Solution {
public:
    bool isSubseq(string&s, string &curr, int &k){
        int i=0, j=0;
        int n = s.size();
        int m = curr.size();
        int L = m*k;
        while(i<n && j<L){
            if(s[i] == curr[j%m])
                j++;
            i++;
        }
        return j>=L;
    }
    bool backtrack(string &s, string &curr, vector<int> &idx, int len, int &k, string &res){
        if(curr.size() == len){
            if(isSubseq(s, curr, k)){
                res = curr;
                return true;
            }
            return false;
        }
        for(int i=25; i>=0; i--){
            if(idx[i] == 0) continue;
            curr.push_back(i+'a');
            idx[i]--;
            if(backtrack(s, curr, idx, len, k, res))
                return true;
            idx[i]++;
            curr.pop_back();
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> f(26);
        int n = s.length();
        for(char c : s)
            f[c-'a']++;
        vector<int> idx(26);
        for(int i=0; i<26; i++)
            idx[i] = f[i]/k;
        int mxlen = n/k;
        string res = "";
        string curr = "";
        for(int i=mxlen; i>=1; i--){
            if(backtrack(s, curr, idx, i, k, res))
                break;
        }
        return res;
    }
};