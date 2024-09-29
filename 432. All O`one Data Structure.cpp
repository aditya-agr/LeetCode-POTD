class AllOne {
public:
    struct Node{
        list<string> keys;
        Node* next;
        Node* prev;
        int cnt;

        Node(int k){
            cnt = k;
            next = NULL;
            prev = NULL;
        }
    };
    unordered_map<string, Node*> mp;
    Node *head, *tail;
    AllOne() {
        head = new Node(0);
        tail = head;
    }

    void inc(string key) {
        if(mp.find(key) == mp.end()){
            if(head->next==NULL || head->next->cnt != 1)
                addNode(head, 1);
            head->next->keys.push_back(key);
            mp[key] = head->next;
        }
        else{
            Node *curr = mp[key];
            int curcnt = curr->cnt;
            if(curr->next==NULL || curr->next->cnt != curcnt+1)
                addNode(curr, curcnt+1);
            curr->next->keys.push_back(key);
            mp[key] = curr->next;
            curr->keys.remove(key);
            if(curr->keys.empty())
                removeNode(curr);
        }
    }
    
    void dec(string key) {
        Node *curr = mp[key];
        int curcnt = curr->cnt;
        if(curcnt == 1)
            mp.erase(key);
        else{
            if(curr->prev->cnt != curcnt-1)
                addNode(curr->prev, curcnt-1);
            curr->prev->keys.push_back(key);
            mp[key] = curr->prev;
        }
        curr->keys.remove(key);
        if(curr->keys.empty())
            removeNode(curr);      
    }
    void addNode(Node* pre, int cnt){
        Node * newNode = new Node(cnt);
        newNode->next = pre->next;
        newNode->prev = pre;
        if(newNode->next)
            newNode->next->prev = newNode;
        pre->next = newNode;
        if(pre == tail)
            tail = pre->next;
    }
    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        if(node == tail)
            tail = node->prev;
        delete node;
    }
    
    string getMaxKey() {
        if(tail == head)
            return "";
        return tail->keys.back();
    }
    
    string getMinKey() {
        if(head->next == NULL)
            return "";
        return head->next->keys.back();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */