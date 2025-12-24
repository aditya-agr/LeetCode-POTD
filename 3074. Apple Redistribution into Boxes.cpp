class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());

        int tot = 0;
        for(int x : apple)
            tot += x;
        
        int cnt = 0;
        for(int b : capacity){
            tot -= b;
            cnt++;
            if(tot <= 0)
                return cnt;
        }
        return -1;
    }
};