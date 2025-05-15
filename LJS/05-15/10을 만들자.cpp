#include <iostream>
using namespace std;
int cnt;
int lim;
void dfs(int lev,int sum) {
	if (sum > 10)return;
	if (lev == lim) {
		if (sum == 10) {
			cnt++;
		}
		return;
	}
	for (int i = 1; i < 11; i++) {
		dfs(lev + 1, sum + i);
	}
}
int main() {
	cin >> lim;
	dfs(0, 0);
	cout << cnt;
}