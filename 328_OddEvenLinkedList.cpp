//self-write
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode dummy1(-1);
        ListNode* odd = &dummy1;
        ListNode dummy2(-1);
        ListNode* even = &dummy2;
        int count = 1;
        for (ListNode* curr = head; curr; curr = curr->next){
            if (count%2 != 0) {
                odd->next = curr;
                odd = odd->next;
            } else {
                even->next = curr;
                even = even->next;
            }
            count++;
        }
        odd->next = dummy2.next;
        even->next = NULL;
        return dummy1.next; 
    }
};
//Better way
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pOdd = head;
        ListNode *pEven = head->next;
        ListNode *pEvenHead = head->next;

        while (pOdd->next != nullptr) {
            ListNode *p = pOdd->next;
            p = p->next;
            pOdd->next = p;
            if (p != nullptr) {
                pOdd = pOdd->next;
            }
            p = pEven->next;
            if (p == nullptr) {
                break;
            }
            p = p->next;
            pEven->next = p;
            if (p != nullptr) {
                pEven = pEven->next;
            }
        }

        pOdd->next = pEvenHead;
        return head;
    }
};