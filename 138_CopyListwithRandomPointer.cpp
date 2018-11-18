/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //1. copy the node and insert the new node between two original nodes
        if (head == NULL) return head;
        RandomListNode* curr;
        for (curr = head; curr != NULL;){
            RandomListNode * node = new RandomListNode (curr->label);
            node->next = curr->next; 
            curr->next = node;
            curr = node->next;        
        }
        //2. copy the random pointer
        for (curr = head; curr != NULL;){
            if (curr->random != NULL) curr->next->random = curr->random->next; //need to check if random is NULL
            curr = curr->next->next;
        }
        //3. restore the original list and copied list
        RandomListNode dummy(-1);
        RandomListNode* new_node = &dummy;
            for (curr = head; curr != NULL;){
                new_node->next = curr->next;
                new_node = new_node->next;
                curr->next = curr->next->next;
                curr = curr->next;
            }
        return dummy.next;  
    }
};