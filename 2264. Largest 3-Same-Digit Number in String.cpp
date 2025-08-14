class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char mx = -1;
        string res = "";
        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2] && mx < num[i]){
                res = num.substr(i, 3);
                mx = num[i];
            }
        }
        return res;
    }
};