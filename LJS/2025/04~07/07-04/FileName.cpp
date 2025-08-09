#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int num;
	long long cost;
};
int M, N;
long long dist[100000];
vector<Edge> v[100000];
struct cmp {
	bool operator()(Edge A, Edge B) {
		return A.cost > B.cost;
	}
};
void dijk(int st) {
	priority_queue<Edge, vector<Edge>,cmp> pq;
	pq.push({st,0});
	dist[st] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (dist[now.num] < now.cost)continue;
		for (int i = 0; i < v[now.num].size(); i++) {
			long long nextCost = now.cost + v[now.num][i].cost;
			int nextNum = v[now.num][i].num;
			if (nextCost < dist[nextNum]) {
				dist[nextNum] = nextCost;
				pq.push({ nextNum,nextCost });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int a, b,c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i < N; i++) {
		dist[i] = LLONG_MAX;
	}
	dijk(0);
	if (dist[N - 1] == LLONG_MAX) {
		cout << "impossible";
	}
	else {
		cout << dist[N - 1];
	}
	
}