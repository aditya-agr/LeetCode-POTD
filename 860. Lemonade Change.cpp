class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0, cnt10=0;
        for(int bil : bills){
            if(bil==5) 
                cnt5++;
            else if(bil==10){
                cnt10++;
                cnt5--;
            }
            else{
                if(cnt10>0)
                    cnt10--, cnt5--;
                else
                    cnt5 -= 3;
            }
            if(cnt5<0 || cnt10<0)
                return false;
        }
        return true;
    }
};