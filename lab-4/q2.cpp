#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

void displayCircular(Node* head) {
    if (!head) return;
    Node* cur = head;
    while (cur->next != head) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << cur->data << " " << head->data << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* p = new Node(x);
        if (!head) { head = tail = p; }
        else { tail->next = p; tail = p; }
    }

    tail->next = head;

    displayCircular(head);

    return 0;
}
