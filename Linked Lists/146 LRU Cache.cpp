class LRUCache {
    private:
        struct Node {
            int key, value;
            Node* prev;
            Node* next;
            Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        };
    
        unordered_map<int, Node*> cache; // HashMap (key -> node)
        Node* head; // Dummy head (Most Recently Used - MRU)
        Node* tail; // Dummy tail (Least Recently Used - LRU)
        int capacity, size;
    
        // Move node to the front (MRU)
        void moveToFront(Node* node) {
            removeNode(node);
            insertAtFront(node);
        }
    
        // Remove node from DLL
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    
        // Insert node at front (MRU)
        void insertAtFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    
    public:
        LRUCache(int cap) : capacity(cap), size(0) {
            head = new Node(-1, -1); // Dummy head
            tail = new Node(-1, -1); // Dummy tail
            head->next = tail;
            tail->prev = head;
        }
    
        int get(int key) {
            if (cache.find(key) == cache.end()) return -1;
    
            Node* node = cache[key];
            moveToFront(node); // Move accessed node to MRU
            return node->value;
        }
    
        void put(int key, int value) {
            if (cache.find(key) != cache.end()) {
                Node* node = cache[key];
                node->value = value;
                moveToFront(node);
            } else {
                if (size == capacity) {
                    Node* lru = tail->prev;
                    cache.erase(lru->key);
                    removeNode(lru);
                    delete lru;
                    size--;
                }
    
                Node* newNode = new Node(key, value);
                cache[key] = newNode;
                insertAtFront(newNode);
                size++;
            }
        }
    };
    