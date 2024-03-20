class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*head = list1;
        for(int i=0; i<a-1; i++)
            list1 = list1->next;
        ListNode* nxt = list1->next;
        list1->next = list2;
        while(list1->next)
            list1 = list1->next;
        for(int i=0; i<b-a; i++)
            nxt = nxt->next;
        list1->next = nxt->next;
        return head;
    }
};