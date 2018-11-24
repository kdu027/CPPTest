//24ms answer:
class MyLinkedList {
private:
    struct node{
        int val;
        node *next;
        // node(int x) : val(x), next(nullptr) {}
    };
    node *head;
    node *tail;
    int size;
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size|| index < 0) return -1;
        node *cur = head;
        // while(cur!=nullptr){
        //     cout<<" no. "<<cur->val;
        //     cur = cur->next;
        // }
        for(int i = 0;i<index;++i){
            cur = cur->next;
        }
        
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *temp = new node();
        temp->val = val;
        temp->next = head;
        head = temp;
        if(size==0) tail = temp;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *temp = new node();
        temp->val = val;
        if(size==0) {
            tail = temp;
            head = temp;
        }
        tail->next = temp;
        tail = temp;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size || index < 0) return;
        else if(index == 0) {
            addAtHead(val);
            return;
        }
        else if(index == size) {
            addAtTail(val);
            return;
        }
        node *cur = head;
        for(int i = 0;i<index-1;++i){ //find the index-1th node
            cur = cur->next;
        }
        node *temp = new node();
        temp->val = val;
        temp->next = cur->next;
        cur->next = temp;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node * toDelete;
        if(index>=size || index < 0) return;
        else if(index == 0){
            toDelete = head; 
            head = head->next;
            delete toDelete;
            --size;
            return;
        } 
        node *cur = head;
        for(int i = 0;i<index-1;++i){
            cur = cur->next;
        }
        toDelete = cur->next;
        cur->next= cur->next->next;
        if(index == size-1) tail = cur;
        delete toDelete;
        size--;
    }
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
//+++++++++++++faster++++++++++++++++++++++++++++++
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
//fastest way
class MyLinkedList {
private:
	std::vector<int> *a;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		a = new std::vector<int>();
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= a->size())
			return -1;

		return a->at(index);
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		a->insert(a->begin(), val);
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		a->push_back(val);
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
        if (index > a->size())
            return;
		a->insert(a->begin() + index, val);
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
        if(index >= a->size())
            return;
		a->erase(a->begin() + index);
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */




//





["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]