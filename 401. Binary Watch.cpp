class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int h=0; h<=11; h++){
            for(int m=0; m<=59; m++){
                int cnt = __builtin_popcount(h);
                cnt += __builtin_popcount(m);
                if(cnt == turnedOn){
                    string s = to_string(h) + ":" + ((m<10) ? "0" : "") + to_string(m);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};