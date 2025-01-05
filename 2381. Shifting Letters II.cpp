class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> idx(n+1);
        for(auto sh : shifts){
            if(sh[2]==1){
                idx[sh[0]]++;
                idx[sh[1]+1]--;
            }
            else{
                idx[sh[0]]--;
                idx[sh[1]+1]++;
            }
        }
        for(int i=1; i<=n; i++)
            idx[i] += idx[i-1];
        
        string res="";
        for(int i=0; i<n; i++){
            int tmp = s[i]-'a'+idx[i];
            int rem = (abs(tmp)+26)/26;
            tmp += rem*26;
            tmp %= 26;
            res += ('a'+tmp);
        }
        return res;
    }
};