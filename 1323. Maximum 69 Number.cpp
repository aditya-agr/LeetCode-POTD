class Solution {
public:
    int maximum69Number (int num) {
        string val = to_string(num);
        int n = val.length();
        for(int i=0; i<n; i++){
            if(val[i] == '6'){
                val[i] = '9';
                break;
            }
        }
        return stoi(val);
    }
};