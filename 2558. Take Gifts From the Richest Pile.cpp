class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long sum = 0;
        for(int gift : gifts)
            sum += gift;
        
        while(k--){
            int curr = pq.top();
            pq.pop();
            int rem = sqrt(curr);
            sum -= (curr-rem);
            pq.push(rem);
        }
        return sum;
    }
};