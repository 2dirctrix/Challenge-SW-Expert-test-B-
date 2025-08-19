#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    // 맨 앞 삽입
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 맨 뒤 삽입
    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }

    // 특정 값 삭제
    bool remove(int val) {
        if (!head) return false;

        if (head->data == val) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val) {
            cur = cur->next;
        }
        if (!cur->next) return false;
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        return true;
    }

    // 값 검색
    bool search(int val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == val) return true;
            cur = cur->next;
        }
        return false;
    }

    // 출력
    void printList() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // 메모리 해제
    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.insertBack(30);

    cout << "현재 리스트: ";
    list.printList();

    cout << "20 검색: " << (list.search(20) ? "있음" : "없음") << "\n";

    list.remove(10);
    cout << "10 삭제 후 리스트: ";
    list.printList();

    list.remove(5);
    cout << "5 삭제 후 리스트: ";
    list.printList();

    return 0;
}
