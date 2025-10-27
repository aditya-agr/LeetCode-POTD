class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev = 0, curr = 0;
        for(string s : bank){
            curr = 0;
            for(char c : s){
                if(c == '1')
                    curr++;
            }
            res += prev*curr;
            if(curr!=0)
                prev = curr;
        }
        return res;
    }
};