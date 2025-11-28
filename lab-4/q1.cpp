#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v): data(v), prev(nullptr), next(nullptr) {}
};

class CircularList {
public:
    Node* head;
    CircularList(): head(nullptr) {}

    void insert_first(int val) {
        Node* p = new Node(val);
        if (!head) { p->next = p; head = p; return; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        p->next = head;
        tail->next = p;
        head = p;
    }

    void insert_last(int val) {
        Node* p = new Node(val);
        if (!head) { p->next = p; head = p; return; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = p;
        p->next = head;
    }

    void insert_before_after(int key, int val, int mode) {
        if (!head) return;
        if (mode == 0) {
            if (head->data == key) { insert_first(val); return; }
            Node* prev = head;
            Node* cur = head->next;
            while (cur != head && cur->data != key) { prev = cur; cur = cur->next; }
            if (cur == head) return;
            Node* p = new Node(val);
            prev->next = p;
            p->next = cur;
        } else {
            Node* cur = head;
            while (cur->next != head && cur->data != key) cur = cur->next;
            if (cur->data != key && cur->next == head) return;
            Node* p = new Node(val);
            p->next = cur->next;
            cur->next = p;
        }
    }

    void delete_value(int key) {
        if (!head) return;
        if (head->data == key) {
            if (head->next == head) { delete head; head = nullptr; return; }
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            Node* t = head;
            head = head->next;
            tail->next = head;
            delete t;
            return;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur != head && cur->data != key) { prev = cur; cur = cur->next; }
        if (cur == head) return;
        prev->next = cur->next;
        delete cur;
    }

    int search(int key) {
        if (!head) return -1;
        Node* cur = head;
        int pos = 1;
        do {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        } while (cur != head);
        return -1;
    }

    void show() {
        if (!head) { cout << "Empty\n"; return; }
        Node* cur = head;
        bool first = true;
        do {
            if (!first) cout << "->";
            cout << cur->data;
            first = false;
            cur = cur->next;
        } while (cur != head);
        cout << "\n";
    }

    void clear_all() {
        if (!head) return;
        Node* cur = head->next;
        while (cur != head) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
        delete head;
        head = nullptr;
    }
};

class DoublyList {
public:
    DNode* head;
    DoublyList(): head(nullptr) {}

    void insert_first(int val) {
        DNode* p = new DNode(val);
        if (!head) { head = p; return; }
        p->next = head;
        head->prev = p;
        head = p;
    }

    void insert_last(int val) {
        DNode* p = new DNode(val);
        if (!head) { head = p; return; }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = p;
        p->prev = t;
    }

    void insert_before_after(int key, int val, int mode) {
        if (!head) return;
        DNode* cur = head;
        while (cur && cur->data != key) cur = cur->next;
        if (!cur) return;
        if (mode == 0) {
            DNode* p = new DNode(val);
            p->next = cur;
            p->prev = cur->prev;
            if (cur->prev) cur->prev->next = p;
            else head = p;
            cur->prev = p;
        } else {
            DNode* p = new DNode(val);
            p->prev = cur;
            p->next = cur->next;
            if (cur->next) cur->next->prev = p;
            cur->next = p;
        }
    }

    void delete_value(int key) {
        if (!head) return;
        DNode* cur = head;
        while (cur && cur->data != key) cur = cur->next;
        if (!cur) return;
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        delete cur;
    }

    int search(int key) {
        DNode* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void show() {
        if (!head) { cout << "Empty\n"; return; }
        DNode* cur = head;
        bool first = true;
        while (cur) {
            if (!first) cout << "->";
            cout << cur->data;
            first = false;
            cur = cur->next;
        }
        cout << "\n";
    }

    void clear_all() {
        while (head) {
            DNode* t = head;
            head = head->next;
            delete t;
        }
    }
};

int main() {
    CircularList cl;
    DoublyList dl;
    int type;
    while (true) {
        cout << "\nChoose list type 1 Circular 2 Doubly 3 Exit: ";
        if (!(cin >> type)) break;
        if (type == 3) break;
        if (type != 1 && type != 2) { cout << "Invalid\n"; continue; }
        cout << "1 Insert first\n2 Insert last\n3 Insert before/after a value\n4 Delete a value\n5 Search a value\n6 Show list\n7 Back\nEnter choice: ";
        int ch;
        cin >> ch;
        if (type == 1) {
            if (ch == 1) { int v; cin >> v; cl.insert_first(v); }
            else if (ch == 2) { int v; cin >> v; cl.insert_last(v); }
            else if (ch == 3) {
                int key,v,mode;
                cin >> key >> v >> mode;
                cl.insert_before_after(key,v,mode);
            } else if (ch == 4) { int key; cin >> key; cl.delete_value(key); }
            else if (ch == 5) { int key; cin >> key; int p = cl.search(key); if (p==-1) cout<<"Not found\n"; else cout<<"Position "<<p<<"\n"; }
            else if (ch == 6) cl.show();
            else if (ch == 7) continue;
            else cout<<"Invalid\n";
        } else {
            if (ch == 1) { int v; cin >> v; dl.insert_first(v); }
            else if (ch == 2) { int v; cin >> v; dl.insert_last(v); }
            else if (ch == 3) {
                int key,v,mode;
                cin >> key >> v >> mode;
                dl.insert_before_after(key,v,mode);
            } else if (ch == 4) { int key; cin >> key; dl.delete_value(key); }
            else if (ch == 5) { int key; cin >> key; int p = dl.search(key); if (p==-1) cout<<"Not found\n"; else cout<<"Position "<<p<<"\n"; }
            else if (ch == 6) dl.show();
            else if (ch == 7) continue;
            else cout<<"Invalid\n";
        }
    }
    cl.clear_all();
    dl.clear_all();
    return 0;
}
