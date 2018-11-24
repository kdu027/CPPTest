  ListNode* fast = head, *slow = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //it has cycle
                ListNode* slow2 = head;
                while (slow2 = slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return NULL;





//+++++++++++++++better way+++++
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
    /*bool hasCycle(ListNode * head)
    {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
    return false;
    }*/
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool found = false;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        return slow;
        }
        
    return NULL;
    }
};