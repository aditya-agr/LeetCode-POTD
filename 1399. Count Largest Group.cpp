class Solution {
public:
    int findSum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = 0, cnt = 0;
        for(int i=1; i<=n; i++){
            int sum = findSum(i);
            mp[sum]++;
            if(mp[sum] > maxi){
                maxi = mp[sum];
                cnt = 0;
            }
            if(mp[sum] == maxi)
                cnt++;
        }
        return cnt;
    }
};