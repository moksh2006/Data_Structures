#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Node* p = new Node(x);
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }

    head = reverseList(head);

    Node* t = head;
    while (t) {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL";

    return 0;
}
