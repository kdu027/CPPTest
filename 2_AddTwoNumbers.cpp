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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(-1);
        ListNode* new_node = &dummy;
        int carry = 0;
        while (curr1 != NULL || curr2 != NULL){
            int r1 = (curr1 != NULL)? curr1->val : 0;
            int r2 = (curr2 != NULL)? curr2->val : 0;
            int sum = (r1+r2+carry)%10;
            carry = (r1+r2+carry)/10;
            new_node->next = new ListNode(sum);
            new_node = new_node->next;
            if (curr1 != NULL) curr1 = curr1->next;
            if (curr2 != NULL) curr2 = curr2->next;
        }
        if (carry>0) new_node->next = new ListNode(carry);
        return dummy.next;
    }
};