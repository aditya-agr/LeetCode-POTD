class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Xor = 0;
        for(int x : derived)
            Xor ^= x;
        return Xor == 0;
    }
};