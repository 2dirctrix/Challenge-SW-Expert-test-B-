#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[200] = { 0 }, lst[200] = {0};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lst[i];
	}
	int MIN = -21e8;
	for (int i = 0; i <= n + 5; i++) {
		dp[i] = MIN;
	}

	dp[0] = 0;
	for (int i = 2; i <= n + 5; i++) {
		dp[i] = dp[i - 2] + lst[i];
	}

	dp[7] = lst[7];
	for (int i = 7; i <= n + 5; i++) {
		dp[i] = max(dp[i - 2] + lst[i], dp[i - 7] + lst[i]);
	}
	int ans = -21e8;
	for (int i = n; i <= n + 5; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans;

}