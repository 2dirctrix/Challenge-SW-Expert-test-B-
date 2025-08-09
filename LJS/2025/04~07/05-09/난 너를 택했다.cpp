#include <iostream>
using namespace std;

int main() {
	char str[10];
	int data;
	cin >> str;
	for (int i = 0; i < 4; i++) {
		cin >> data;
		cout << str[data];
	}

	return 0;
}
