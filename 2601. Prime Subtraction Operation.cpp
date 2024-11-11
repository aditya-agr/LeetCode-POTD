class Solution {
public:
    bool isPrime[1000];
    void sieve(){
        fill(isPrime, isPrime+1000, true);
        for(int i=2; i<1000; i++){
            if(isPrime[i] == false)
                continue;
            for(int j=i+i; j<1000; j+=i)
                isPrime[j] = false;
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        sieve();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1])
                continue;
            
            for(int k=2; k<nums[i]; k++){
                if(isPrime[k] && nums[i]-k < nums[i+1]){
                    nums[i] -= k;
                    break;
                }
            }
            if(nums[i] >= nums[i+1])
                return false;
        }
        return true;
    }
};