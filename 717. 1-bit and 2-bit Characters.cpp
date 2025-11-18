class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i=0;
        for(i=0; i<n-1; i++){
            if(bits[i] == 1)
                i++;
        }
        return i==n-1;
    }
};