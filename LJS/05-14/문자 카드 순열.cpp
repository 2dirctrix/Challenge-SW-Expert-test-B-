#include <iostream>
using namespace std;

char name[3];
char path[4];
int used[3];

void run(int level) {
	if (level == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[level] = name[i];
		run(level + 1);
		path[level] = 0;
		used[i] = 0;
	}
}
int main() {
	for (int i = 0; i < 3; i++) cin >> name[i];

	run(0);
}