class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string str2 = str;
        int idx = str.find_first_not_of('9');
        if(idx != string::npos){
            char ch = str[idx];
            replace(str.begin(), str.end(), ch, '9');
        }
        if(str2[0] != '1'){
            char ch = str2[0];
            replace(str2.begin(), str2.end(), ch, '1');
        }
        else{
            int idx2 = str2.find_first_not_of("01");
            if(idx2 != string::npos){
                char ch = str2[idx2];
                replace(str2.begin(), str2.end(), ch, '0');
            }
        }
        return stoi(str) - stoi(str2);
    }
};