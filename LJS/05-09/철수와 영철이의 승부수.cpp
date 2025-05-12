#include <iostream>
#include<string>
using namespace std;

int main() {
	for (int i = 0; i < 8; ++i) {
		int win = 0;
		string result = "";
		for (int j = 2; j >= 0; --j) {
			if ((i >> j) & 1) {
				result += "ÆÐ";
			}
			else {
				result += "½Â";
				win++;
			}
		}
		int lose = 3 - win;
		cout << win << "½Â" << lose << "ÆÐ(" << result<< ")\n";
	}

	return 0;
}
