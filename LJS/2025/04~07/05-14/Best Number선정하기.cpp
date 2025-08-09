#include <iostream>
#include<algorithm>
using namespace std;
int lst[5];
int num[5];
int MAX = -21e8;
int MIN = 21e8;

int used[5] = { 0 };
void dfs(int lev) {
	if (lev==5) {
		int tmp= (num[0] * num[1]) - (num[2] * num[3]) + num[4];
		MAX = max(MAX,tmp);
		MIN = min(MIN, tmp);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (used[i])continue;
		used[i] = 1;
		num[lev] = lst[i];
		dfs(lev + 1);
		used[i] = 0;

	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> lst[i];
	}
	dfs(0);
	cout << MAX << endl << MIN;
}