class Solution {
public:
    bool isPrefixAndSuffix(string &a, string &b){
        bool res = true;
        int n = a.length(), m = b.length();
        int i=0, j=0;
        while(i<n && j<m){
            if(a[i++] != b[j++])
                res = false;
        }
        if(i!=n) return false;
        i=n-1, j=m-1;
        while(i>=0 && j>=0){
            if(a[i--] != b[j--])
                res = false;
        }
        if(i!=-1) return false;
        return res;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};