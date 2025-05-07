#include <iostream>
using namespace std;
int num[5] = { 0 };
int cnt = 0;
void dfs(int lev,int sum,int start) {
	if (sum > 20) {
		return;
	}
	else if (10<=sum and sum<=20) {
		cnt += 1;
	}
	for (int i = start; i < 5; i++) {
		dfs(lev + 1, sum+num[i], i + 1);
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	dfs(0, 0, 0);
	cout << cnt;
}