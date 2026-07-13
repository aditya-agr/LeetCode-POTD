class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;
        for(int i=1; i<9; i++)
            q.push(i);
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num > high)
                break;
            if(num >= low)
                res.push_back(num);
            int rem = num%10;
            if(rem != 9)
                q.push(num*10 + (rem+1));
        }
        return res;

    }
};