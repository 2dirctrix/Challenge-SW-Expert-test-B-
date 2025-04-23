#include <iostream>
#include <cstring>
using namespace std;
char name[5];
char path[5];

void dfs(int lev,int lim,int len) {
	if (lev == lim) {
		cout << path << endl;
		return;
	}
	for (int i = 0; i < len; i++) {
		path[lev] = name[i];
		dfs(lev + 1, lim, len);
		path[lev] = 0;
	}
}

int main() {
	cin >> name;
	int pick;
	int len = strlen(name);
	cin >> pick;
	dfs(0, pick,len);
}