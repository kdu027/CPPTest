//Self_write
class DLinkNode{
    int val;
    int key;
    DLinkNode* prev=NULL;
    DLinkNode* next=NULL;
    friend class LRUCache;
};
class LRUCache {
public:
    // declare all class variables
        unordered_map<int, DLinkNode*> m;
        DLinkNode* head = new DLinkNode;
        DLinkNode* tail = new DLinkNode;
        int count;
        int cap;
    //declear functions
    void addHead(DLinkNode* node){
        if (!node) return;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void remove(DLinkNode* node){
        if (!node) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    void moveToHead(DLinkNode* node){
        remove(node); //Order is important, first remove and then add!
        addHead(node);    
    }
    DLinkNode* popTail(){
        DLinkNode* node = tail->prev;
        remove(node);
        return node;
    }
    //main
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        count = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        moveToHead(m[key]);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()){
            DLinkNode* node = new DLinkNode;
            node->key = key;
            node->val = value;
            addHead(node);
            m[key]=node;
            count++;
            //Need to check the capcacity!!!
            if(count>cap){
                DLinkNode *t=popTail();
                m.erase(t->key);
                count--;
            }
        } else{
            m[key]->val = value;
            moveToHead(m[key]);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//way1: +++++++++++++++++++++++++++
class DLinkNode{
    int key;
    int val;
    DLinkNode *next;
    DLinkNode *prev;
    
    friend class LRUCache; //class LRUCache can access the private memebr in DLinkNode
};



class LRUCache {
    unordered_map<int,DLinkNode*> m;
    DLinkNode *head; //not allocate memory yet, it is just a pointer
    DLinkNode *tail;
    int count;
    int cap;
    
    void addAtHead(DLinkNode *node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    
    void remove(DLinkNode *node){
        DLinkNode *front=node->next;
        DLinkNode *back=node->prev;
        
        front->prev=back;
        back->next=front;
    }
    
    void moveToHead(DLinkNode *node){
        remove(node);
        addAtHead(node);
    }
    
    DLinkNode *popTail(){
        DLinkNode *pre=tail->prev;
        remove(pre);
        return pre;
    }
public:
    LRUCache(int capacity) {
        
        head=new DLinkNode(); //request memory for the variable head
        tail=new DLinkNode();
        head->prev=NULL;
        head->next=tail;
        tail->next=NULL;
        tail->prev=head;
        count=0;
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        
        DLinkNode *node=m[key]; //if find the value, move it to the head, cache hit
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) { //1. add node 2. remove the last used node
        
        if(m.find(key)==m.end()){
            DLinkNode *node=new DLinkNode();
            node->key=key;
            node->val=value;
            addAtHead(node); //Add the new node to the head of the queue
            m[key]=node;
            count++;
            
            if(count>cap){ 
                DLinkNode *t=popTail();
                m.erase(t->key); //erase(int key);
                count--;
            }
        }
        else{
            m[key]->val=value;
            moveToHead(m[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

//way2:==============================
 struct MyNode {
public:
    int key;
    int value;
    MyNode* pre;
    MyNode* post;
};


class LRUCache {
    int c;
    unordered_map<int, MyNode*> m;
    MyNode* head;
    MyNode* tail;
    int size;
public:
    LRUCache(int capacity) : c(capacity) {
        head = new MyNode();
        head->pre = nullptr;
        tail = new MyNode();
        tail->post = nullptr;
        
        head->post = tail;
        tail->pre = head;
    }
    
    // add the new node right after head
    void addNode(MyNode* node) {
        node->pre = head;
        node->post = head->post;
        
        head->post->pre = node;
        head->post = node;
    }
    
    void removeNode(MyNode* node) {
        MyNode* pre = node->pre;
        MyNode* post = node->post;
        
        pre->post = post;
        post->pre = pre;
        
        // delete node;
    }
    
    void moveToHead(MyNode* node) {
        removeNode(node);
        addNode(node);
    }
    
    void popTail() {
        MyNode* pre = tail->pre;
        removeNode(pre);
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        moveToHead(it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        // key existed
        if (it != m.end()) {
            it->second->value = value;
            moveToHead(it->second);
            return;
        }
        
        // out of capacity
        if (c == m.size()) {
            // pop tail
            m.erase(tail->pre->key);
            popTail();
        }
        // add new element
        MyNode* newNode = new MyNode();
        newNode->key = key;
        newNode->value = value;
        
        m[newNode->key] = newNode;
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */