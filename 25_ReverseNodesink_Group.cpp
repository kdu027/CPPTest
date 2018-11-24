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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check head and k
        if (head==NULL || head->next==NULL || k<=1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev_list = &dummy;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int len = 0;
        int reverseCount = 0;
        //check length
        while (curr != NULL){
            curr = curr->next;
            len++;
        }
        //reverse
        curr = head; //reset curr to head;
        while(curr!=NULL && len>=k){ //!curr means when curr == NULL works
           ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            reverseCount++;
            
            if (reverseCount % k == 0){
                prev_list->next = prev;
                prev_list = head;
                head = curr;
                prev = NULL;
                len = len-k;
            }
        }
        if (len !=0){
            prev_list->next = head;
        } else {
            prev_list->next = prev;
        }
        return dummy.next;
    }
};