#include <iostream>
#include <string>
using namespace std;
char path[3];
string str;
void run(int level, int start) {
	if (level == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = start; i < str.length(); i++) {
		path[level] = str[i];
		run(level + 1,i);
		path[level] = 0;
	}
}
int main() {
	for (int i = 0; i < 4; i++) cin >> str;

	run(0,0);
}