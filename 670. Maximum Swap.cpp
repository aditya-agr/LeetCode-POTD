class Solution {
public:
    int maximumSwap(int nums) {
        string num = to_string(nums);
        int n = num.size();
        vector<int> mx(n);
        mx[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            if(num[mx[i+1]] >= num[i])
                mx[i] = mx[i+1];
            else
                mx[i] = i;
        }
        for(int i=0; i<n; i++){
            if(num[i] < num[mx[i]]){
                swap(num[i], num[mx[i]]);
                break;
            }
        }
        return stoi(num);
    }
};