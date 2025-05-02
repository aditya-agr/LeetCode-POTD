class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n);
        vector<int> right(n);
        int r = -1, l = -1;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R')
                r = i;
            if(dominoes[i] == 'L')
                r = -1;
            right[i] = r;

        }
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L')
                l = i;
            if(dominoes[i] == 'R')
                l = -1;
            left[i] = l;
        }
        string res = dominoes;
        for(int i=0; i<n; i++){
            if(res[i] == '.'){
                int llen = abs(i-left[i]);
                int rlen = abs(i-right[i]);
                if(left[i] == -1 && right[i] == -1)
                    continue;
                else if(left[i] == -1)
                    res[i] = 'R';
                else if(right[i] == -1)
                    res[i] = 'L';
                else if(llen > rlen)
                    res[i] = 'R';
                else if(llen < rlen)
                    res[i] = 'L';
            }
        }
        return res;
    }
};