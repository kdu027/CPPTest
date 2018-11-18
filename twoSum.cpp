#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // assume m<n
        if (m==n) return head;
        if (m>n) return reverseBetween(head, n, m);
        // revs and revend is start and end respectively
        // of the portion of the linked list which
        // need to be reversed. revs_prev is previous
        // of starting position and revend_next is next
        // of end of list to be reversed.
        ListNode* revs = NULL, *revs_prev = NULL;
        ListNode* revend = NULL, *revend_next = NULL;
        ListNode* curr=head;
        for (int i=1;i<=n; i++){
            if (!curr) break;
            if (i == m-1) revs_prev = curr;
            if (i == m) revs = curr;
            if (i == n) {
                revend = curr;
                revend_next = curr->next;
            }
            curr = curr->next;
        }
        revend->next = NULL;
        // ListNode* new_head = reverseList(revs);
        print(revs);
        return revs;
    }
private:
    void print(ListNode* head)
    {
        while (head != NULL) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);
    
    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }
    
    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().reverseBetween(head, m, n);
        
        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
