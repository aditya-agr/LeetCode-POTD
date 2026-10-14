class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int max = sum/9;
        string res = string(max, '9');
        if(sum%9)
            res.push_back('0'+sum%9);
        int n = res.size();
        if(n > num)
            return "";
        num -= n;
        res += string(num, '0');
        return res;
    }
};