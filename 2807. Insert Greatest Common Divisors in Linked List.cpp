class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head, *nxt=head->next;
        while(nxt){
            int a = curr->val;
            int b = nxt->val;
            int gcd = __gcd(a, b);
            ListNode* node = new ListNode(gcd);
            node->next = curr->next;
            curr->next = node;
            curr = nxt;
            nxt = curr->next;
        }
        return head;
    }
};