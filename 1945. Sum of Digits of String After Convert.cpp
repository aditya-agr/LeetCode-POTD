class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        for(char c : s){
            int num = (c-'a')+1;
            string n = to_string(num);
            res += n;
        }
        while(k--){
            int curr = 0;
            for(char c : res)
                curr += (c-'0');
            res = to_string(curr);
        }
        return stoi(res);
            
    }
};