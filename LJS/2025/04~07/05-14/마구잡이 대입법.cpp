#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int lev,int trgt,int sum) {
	if (lev == trgt) {
		if (sum == 7) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		dfs(lev + 1, trgt, sum + i);
	}
}
int main() {
	int n;
	cin >> n;
	dfs(0, n, 0);
	cout << cnt;

}