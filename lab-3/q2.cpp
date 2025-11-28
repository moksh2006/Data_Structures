#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

int countAndDelete(Node*& head, int key) {
    int cnt = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        cnt++;
    }
    if (!head) return cnt;
    Node* prev = head;
    Node* cur = head->next;
    while (cur) {
        if (cur->data == key) {
            prev->next = cur->next;
            delete cur;
            cnt++;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return cnt;
}


};

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
    int key;
    cin >> key;
    int cnt = countAndDelete(head, key);
    cout << "Count: " << cnt << " , Updated Linked List: ";
    Node* t = head;
    if (!t) cout << "Empty";
    else {
        while (t) {
            cout << t->data;
            if (t->next) cout << "->";
            t = t->next;
        }
    }
    cout << "\n";
    
    return 0;
}
