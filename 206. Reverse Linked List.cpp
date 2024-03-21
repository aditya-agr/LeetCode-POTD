class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative Approach
        // ListNode *prev=NULL, *curr=head, *nxt;
        // while(curr){
        //     nxt = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }
        // return prev;

        // Recursive approach
        if(!head || !head->next)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next=NULL;
        return newhead;
    }
};