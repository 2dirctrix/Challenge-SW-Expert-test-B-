#include<iostream>
#include<algorithm>
using namespace std;

int N, M,MIN=21e8;
int card[50],ans[50],path[50];

void dfs(int lev, int cal, int start) {
	if (lev == M) {
		if (cal < MIN) {
			MIN = cal;
			for (int i = 0; i < M; i++) {
				ans[i] = path[i];
			}
		}
		return;
	}
	for (int i = start; i < N; i++) {
		path[lev] = card[i];
		dfs(lev + 1, cal*card[i],i+1);
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	dfs(0, 1,0);
	sort(ans,ans+M);
	for (int i = 0; i < M; i++) {
		cout << ans[i]<<' ';
	}
}