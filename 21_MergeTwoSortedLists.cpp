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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        ListNode* curr1 = l1, *curr2 = l2;
        for (; curr1 && curr2; curr=curr->next){
            if (curr1->val <= curr2->val){
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
        }
        curr->next = curr1? curr1:curr2;
        return dummy.next;
    }
};