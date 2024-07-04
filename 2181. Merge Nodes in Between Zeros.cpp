class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int curr=0;
        ListNode* temp = new ListNode(0), *nwhead = temp;
        temp->next = head;
        head = head->next;
        while(head){
            if(head->val)
                curr += head->val;
            else{
                ListNode* node = new ListNode(curr);
                temp->next = node;
                temp = temp->next;
                curr=0;
            }
            head = head->next;
        }
        return nwhead->next;
    }
};