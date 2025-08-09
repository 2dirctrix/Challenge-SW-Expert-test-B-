#include<iostream>
#include<vector>
using namespace std;
vector<int> num = {0,1};
void fib(int lev,int trgt) {
	if (lev == trgt) {
		cout << num[lev-1];
		return;
	}
	if (lev <2) {
		fib(lev + 1, trgt);
	}
	else {
		num.push_back(num[lev-1]+num[lev-2]);
		fib(lev + 1, trgt);
	}
}
int main() {
	int n;
	cin >> n;
	fib(0, n);
	return 0;
}