#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;*
 for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Node* p = new Node(x);
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }

    cout << findMiddle(head) << endl;

    return 0;
}
