/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;
        int len = 0;
        while (q->next){
            if (len<n){
                q = q->next;
                len++;
            } else{
                q = q->next;
                p = p->next;
            }  
        }
        ListNode* temp = p->next;
        p->next = p->next->next;
        delete temp;
        return dummy.next; //return dummy.next instead of head
    }
};