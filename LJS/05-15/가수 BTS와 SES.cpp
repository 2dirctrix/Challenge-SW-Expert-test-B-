#include <iostream>
#include <string>
using namespace std;
string str[5] = {"BTS","SBS","BS","CBS","SES"};
string trgt;
int MIN = 7;
void dfs(int lev,string sum) {
	if (sum.length() > trgt.length())return;
	if (sum == trgt) {
		if (MIN > lev)MIN = lev;
		return;
	}
	for (int i = 0; i < 5; i++) {
		int n = sum.length();
		if (str[i][0] == trgt[n]) {
			dfs(lev + 1, sum + str[i]);
		}
	}
}
int main() {
	cin >> trgt;
	dfs(0,"");
	cout << MIN;
}