#include <iostream>
#include <string>
using namespace std;

string str;
int price[150];
int used[150];
int MAX;

int selectt=0;
void dfs(int lev, int sum) {
	if (lev == selectt) {
		if (sum % 10 == 0 && MAX < sum) {
			MAX = sum;
		}
		return;
	}
	for (int i = 0; i < str.length(); i++) {
		if (used[i]==1)continue;
		used[i] = 1;
		dfs(lev + 1, sum + price[str[i]]);
		used[i] = 0;
	}
}


int main() {
	price['a'] = 15;
	price['b'] = 20;
	price['c'] = 44;
	price['d'] = 22;
	price['e'] = 55;
	price['f'] = 16;
	price['g'] = 45;
	int n;
	cin >> str;
	cin >> n;
	selectt = str.length() - n;

	dfs(0,0);
	cout << MAX;
}