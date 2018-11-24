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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for (ListNode* prev= &dummy, *curr = head, *next = head->next;next;prev=curr, curr=curr->next, next = curr?curr->next:NULL){
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
        }
        return dummy.next;   
    }
};