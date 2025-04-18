class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string str = countAndSay(n-1);
        int cnt=0; 
        char ele=str[0];
        string res = "";
        for(char c : str){
            if(c == ele)
                cnt++;
            else{
                res += to_string(cnt) + ele;
                cnt = 1;
                ele = c;
            }
        }
        res += to_string(cnt) + ele;
        return res;
    }
};