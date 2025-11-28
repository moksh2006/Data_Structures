#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int v): data(v), next(nullptr), prev(nullptr) {}
};


int sizeCircular(Node* head) {
    if (!head) return 0;
    int count = 1;
    Node* cur = head->next;
    while (cur != head) {
        count++;
        cur = cur->next;
    }
    return count;
}


int sizeDoubly(DNode* head) {
    int count = 0;
    DNode* cur = head;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

int main() {
    int n;

    
    cin >> n;
    Node* chead = nullptr;
    Node* ctail = nullptr;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        Node* p = new Node(x);
        if (!chead) chead = ctail = p;
        else { ctail->next = p; ctail = p; }
    }
    ctail->next = chead;

    cout << "Size of Circular Linked List: " << sizeCircular(chead) << endl;

    // Doubly Linked List
    cin >> n;
    DNode* dhead = nullptr;
    DNode* dtail = nullptr;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        DNode* p = new DNode(x);
        if (!dhead) dhead = dtail = p;
        else { dtail->next = p; p->prev = dtail; dtail = p; }
    }

    cout << "Size of Doubly Linked List: " << sizeDoubly(dhead) << endl;

    return 0;
}
