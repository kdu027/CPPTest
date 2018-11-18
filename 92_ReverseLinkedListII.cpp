class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // assum m < n
        if (m == n) return head;
        if (m > n) return reverseBetween(head, n, m);
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* prev = newHead;
        for (auto i=1; i<m; i++){
            prev = prev->next;
        }
        ListNode* prevHead = prev; //save the node before mth node
        prev = prev->next;
        ListNode* curr = prev->next;
        //start reverse
        for (auto i=m; i<n; i++){
            if (!curr) break;
            prev->next = curr->next;
            curr->next = prevHead->next; //can not be previous
            prevHead->next = curr;
            curr = prev->next; 
        }
        return newHead->next;
    }
};