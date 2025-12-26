class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cntN = 0;
        for(char c : customers)
            if(c == 'N')
                cntN++;

        int cntY = 0, res = cntN;
        int resIdx = n;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y')
                cntY++;
            else
                cntN--;
            int cur = cntY+cntN;
            if(cur < res){
                res = cur;
                resIdx = i;
            }
            else if(res == cur)
                resIdx = i;
        }
        return resIdx;
    }
};