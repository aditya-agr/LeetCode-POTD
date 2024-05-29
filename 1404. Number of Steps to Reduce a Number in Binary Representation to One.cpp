class Solution {
public:
    int numSteps(string s) {
        int cnt=0, carry=0;
        int i = s.length()-1;
        while(i>0){
            if(s[i]=='0'){
                if(carry)
                    cnt+=2;
                else
                    cnt++;
            }  
            else{
                if(carry)
                    cnt++;
                else{
                    carry = 1;
                    cnt+=2;
                }
            }
            i--;
        } 
        if(carry)
            cnt++;
        return cnt;
    }
    
};