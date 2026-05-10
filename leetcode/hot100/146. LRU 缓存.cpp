// ai改的
struct listnode {
    int key, val;
    listnode *prev, *next;
    listnode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    listnode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    // 哨兵节点（不存数据，避免空指针）
    listnode* head;
    listnode* tail;
    int capacity;
    int size;
    unordered_map<int, listnode*> mp;

    // 移除一个节点
    void removeNode(listnode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 添加到尾部（最新使用）
    void addToTail(listnode* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    // 移动节点到尾部
    void moveToTail(listnode* node) {
        removeNode(node);
        addToTail(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        // 创建两个哨兵节点，head <-> tail
        head = new listnode();
        tail = new listnode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        listnode* node = mp[key];
        moveToTail(node); // 标记为最近使用
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // 已存在：更新值 + 移到尾部
            listnode* node = mp[key];
            node->val = value;
            moveToTail(node);
            return;
        }

        // 新建节点
        listnode* newNode = new listnode(key, value);
        mp[key] = newNode;
        addToTail(newNode);
        size++;

        // 超过容量，删除最久未使用（head->next）
        if (size > capacity) {
            listnode* delNode = head->next;
            removeNode(delNode);
            mp.erase(delNode->key);
            delete delNode;
            size--;
        }
    }
};


/*
自己写的
struct listnode {
    int key,val;
    listnode *prev,*next;
    listnode(): key(0),val(0),prev(NULL),next(NULL) {}
    listnode(int key,int val): key(key),val(val),prev(NULL),next(NULL) {}
};

class LRUCache {
public:
    int cap;
    int sz;
    listnode *head,*tail;
    unordered_map<int,listnode*> mp;

    LRUCache(int capacity) {
        cap=capacity;
        sz=0;
        head=new listnode();
        tail=new listnode();
        head->next=tail;
        tail->prev=head;
    }

    void remove(int key)
    {
        listnode *node=mp[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void move_tail(listnode *node)
    {
        node->prev=tail->prev;
        tail->prev->next=node;
        node->next=tail;
        tail->prev=node;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            listnode *node=mp[key];
            remove(key);
            move_tail(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            listnode *node=mp[key];
            node->val=value;
            remove(key);
            move_tail(node);
            return;
        }
        
        sz++;
        listnode *node=new listnode(key,value);
        move_tail(node);
        mp[key]=node;

        if(sz>cap)
        {
            sz--;
            listnode *tmp=head->next;
            remove(tmp->key);
            mp.erase(tmp->key);
            delete tmp;
        }
    }
};

*/