#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    // 맨 뒤 삽입
    void insertBack(int val) {
        Node* node = new Node(val);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // 특정 값 삭제 (앞에서부터)
    bool remove(int val) {
        Node* cur = head;
        while (cur && cur->data != val) cur = cur->next;
        if (!cur) return false;

        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;

        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;

        delete cur;
        return true;
    }

    // 정방향 출력
    void printForward() {
        for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    cout << "정방향 출력: ";
    list.printForward();

    list.remove(20);
    cout << "20 삭제 후: ";
    list.printForward();

    return 0;
}
