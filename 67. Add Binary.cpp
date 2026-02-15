class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while(i>=0 && j>=0){
            int cur = (a[i]-'0') + (b[j]-'0') + carry;
            if(cur == 3){
                res = "1"+res;
                carry = 1;
            }
            else if(cur == 2){
                res = "0"+res;
                carry = 1;
            }
            else if(cur == 1){
                res = "1"+res;
                carry = 0;
            }
            else{
                res = "0"+res;
                carry = 0;
            }
            i--;
            j--;
        }
        while(i>=0){
            int cur = (a[i]-'0') + carry;
            if(cur == 2){
                res = "0"+res;
                carry = 1;
            }
            else if(cur == 1){
                res = "1"+res;
                carry = 0;
            }
            else{
                res = "0"+res;
                carry = 0;
            }
            i--;
        }
        while(j>=0){
            int cur = (b[j]-'0') + carry;
            if(cur == 2){
                res = "0"+res;
                carry = 1;
            }
            else if(cur == 1){
                res = "1"+res;
                carry = 0;
            }
            else{
                res = "0"+res;
                carry = 0;
            }
            j--;
        }
        if(carry){
            res = "1"+res;
        }
        return res;
    }
};