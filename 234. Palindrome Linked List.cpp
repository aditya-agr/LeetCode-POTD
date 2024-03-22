class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for(int i=0; i<n/2; i++){
            if(arr[i]!=arr[n-i-1])
                return false;
        }
        return true;
    }
};