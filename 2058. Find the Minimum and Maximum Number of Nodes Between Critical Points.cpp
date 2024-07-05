/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1, pre=0, fst=0, mn=INT_MAX, mx=-1;
        ListNode *prev = head, *curr = head->next;
        while(curr->next){
            if((prev->val>curr->val && curr->next->val>curr->val) || 
            (prev->val<curr->val && curr->next->val<curr->val)){
                if(!fst) fst = i;
                if(pre) mn = min(mn, i-pre);
                pre = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        mx = pre - fst;
        if(mx==0 || mn==INT_MAX)
            return {-1,-1};
        return {mn, mx};
    }
};