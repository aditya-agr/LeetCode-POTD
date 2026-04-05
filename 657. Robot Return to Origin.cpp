class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0, v=0;
        for(char &c : moves){
            if(c == 'U') v++;
            if(c == 'D') v--;
            if(c == 'L') h++;
            if(c == 'R') h--;
        }
        return h==0 && v==0;
    }
};