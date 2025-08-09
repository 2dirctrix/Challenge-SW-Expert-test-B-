#include <iostream>
using namespace std;
struct Node {
	int x;
	Node* next;
};
Node* head;
Node* last;
void addNode(int num) {
	if (head == NULL) {
		head = new Node({ num,NULL });
		last = head;
		return;
	}
	last->next = new Node({ num,NULL });
	last = last->next;
}
int main() {
	addNode(3);
	addNode(5);
	addNode(4);
	for (Node* i = head; i != NULL; i->next) {
		cout << i->x;
	}
	return 0;
}