#include <iostream>
#include <list>
using namespace std;
struct Node {
	char a;
};
int main() {
	int n;
	cin >> n;
	list<Node> lst;
	for (int i = 54; i < 58; i++) {
		lst.push_back({ char(i+n) });
	}
	for (auto i = lst.begin(); i != lst.end(); i++) {
		cout << i->a;
	}
}
