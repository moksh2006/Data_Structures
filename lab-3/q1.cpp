#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insert_begin(int val) {
        Node* p = new Node(val);
        p->next = head;
        head = p;
    }

    void insert_end(int val) {
        Node* p = new Node(val);
        if (!head) { head = p; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = p;
    }

    void insert_before_after(int key, int val, int mode) {
        if (!head) return;
        if (mode == 0) {
            if (head->data == key) { insert_begin(val); return; }
            Node* prev = nullptr;
            Node* cur = head;
            while (cur && cur->data != key) { prev = cur; cur = cur->next; }
            if (!cur) return;
            Node* p = new Node(val);
            prev->next = p;
            p->next = cur;
        } else {
            Node* cur = head;
            while (cur && cur->data != key) cur = cur->next;
            if (!cur) return;
            Node* p = new Node(val);
            p->next = cur->next;
            cur->next = p;
        }
    }

    void delete_begin() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void delete_end() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur->next) { prev = cur; cur = cur->next; }
        prev->next = nullptr;
        delete cur;
    }

    void delete_value(int key) {
        if (!head) return;
        if (head->data == key) { delete_begin(); return; }
        Node* prev = head;
        Node* cur = head->next;
        while (cur && cur->data != key) { prev = cur; cur = cur->next; }
        if (!cur) return;
        prev->next = cur->next;
        delete cur;
    }

    int search(int key) {
        int pos = 1;
        Node* cur = head;
        while (cur) {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    void clear_all() {
        while (head) delete_begin();
    }
};

int main() {
    LinkedList ll;
    int choice;
    while (true) {
        cout << "\n1 Insert at beginning\n2 Insert at end\n3 Insert before/after a value\n4 Delete from beginning\n5 Delete from end\n6 Delete a specific value\n7 Search for a value\n8 Display list\n9 Exit\nEnter choice: ";
        if (!(cin >> choice)) break;
        if (choice == 1) {
            int v; cout << "Enter value: "; cin >> v;
            ll.insert_begin(v);
        } else if (choice == 2) {
            int v; cout << "Enter value: "; cin >> v;
            ll.insert_end(v);
        } else if (choice == 3) {
            int key, v, mode;
            cout << "Enter key value: "; cin >> key;
            cout << "Enter new value: "; cin >> v;
            cout << "Enter 0 to insert before, 1 to insert after: "; cin >> mode;
            ll.insert_before_after(key, v, mode);
        } else if (choice == 4) {
            ll.delete_begin();
        } else if (choice == 5) {
            ll.delete_end();
        } else if (choice == 6) {
            int key; cout << "Enter value to delete: "; cin >> key;
            ll.delete_value(key);
        } else if (choice == 7) {
            int key; cout << "Enter value to search: "; cin >> key;
            int pos = ll.search(key);
            if (pos == -1) cout << "Value not found\n"; else cout << "Position from head: " << pos << "\n";
        } else if (choice == 8) {
            ll.display();
        } else if (choice == 9) {
            ll.clear_all();
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}

