#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int v = 0, Node* n = nullptr) : val(v), next(n) {}
};

class LinkedList {
private:
    Node* dummyHead;
    Node* tail;
    int size;

public:
    LinkedList() {
        dummyHead = new Node(-1);
        tail = dummyHead;
        size = 0;
    }

    int get(int i) {
        if (i < 0 || i >= size) {
            return -1;
        }
        Node* curr = dummyHead->next;
        for (int idx = 0; idx < i; ++idx) {
            curr = curr->next;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val, dummyHead->next);
        dummyHead->next = newNode;

        if (size == 0) {
            tail = newNode;
        }
        size++;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    bool remove(int i) {
        if (i < 0 || i >= size) {
            return false;
        }

        Node* curr = dummyHead;
        for (int idx = 0; idx < i; ++idx) {
            curr = curr->next;
        }

        Node* toDelete = curr->next;
        if (toDelete == tail) {
            tail = curr;
        }
        curr->next = toDelete->next;
        delete toDelete;
        size--;

        return true;
    }

    std::vector<int> getValues() {
        std::vector<int> values;
        Node* curr = dummyHead->next;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }

    ~LinkedList() {
        Node* curr = dummyHead;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};