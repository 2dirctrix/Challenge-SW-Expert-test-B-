#include <iostream>
using namespace std;

int memo[35];

int fib(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = fib(n - 1) + fib(n - 2);
	return memo[n];
}
int main() {
	int n;
	cin >> n;

	cout << fib(n+1);
}