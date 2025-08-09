#include <iostream>
using namespace std;

int main() {
	int num[4][4] = { {0,0,0,0},{0,1,1,0},{2,2,3,0},{1,3,3,1} };
	bool flag = false;
	for (int i = 3; i >= 0; i--) {
		for (int j = 3; j > 0; j--) {
			if (num[j - 1][i] > num[j][i]) {
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	if (flag) {
		cout << "안전하지않은성";
	}
	else {
		cout << "안전한성";
	}
}
