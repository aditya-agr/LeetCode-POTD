class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* nhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nhead;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* nh = reverse(head);
        ListNode* nhd = nh, *prev;
        int carry=0;
        while(nh){
            nh->val *= 2;
            nh->val += carry;
            carry = nh->val/10;
            nh->val %= 10;
            prev = nh;
            nh = nh->next;
        }
        if(carry) 
        prev->next = new ListNode(carry);
        nhd = reverse(nhd);
        return nhd;
    }
};