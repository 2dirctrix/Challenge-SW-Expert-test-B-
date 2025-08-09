#include <iostream>

using namespace std;

int main() {
	int num[4][4];
	int check[4];
	for (int i = 0; i < 4; i ++ ) {
		for (int j = 0; j < 4; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num[i][j] == 1) {
				check[i] += 1;
			}
		}
	}
	int MAX=0, index;
	for (int j = 0; j < 4; j++) {
		if (check[j]>MAX) {
			MAX=check[j];
			index = j;
		}
	}
	cout << char('A'+index);
}
