class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        digits[n-1]++;
        for(int i=n-1; i>=0; i--){
            int num = carry + digits[i];
            carry = num/10;
            digits[i] = num%10;
        }
        if(carry)
            digits.insert(digits.begin(),carry);    
        return digits;
    }
};