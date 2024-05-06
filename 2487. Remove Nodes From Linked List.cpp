class Solution {
public:
    ListNode* reverse(ListNode* root){
        ListNode* curr=root, *prev=NULL, *nxt=root->next;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int mx=head->val;
        ListNode* nhead = head, *prev=NULL;
        while(head){
            if(mx<=head->val){
                mx = head->val;
                prev = head;
            }
            else{
                prev->next = head->next;
            }
            head = head->next;
        }
        nhead = reverse(nhead);
        return nhead;
    }
};