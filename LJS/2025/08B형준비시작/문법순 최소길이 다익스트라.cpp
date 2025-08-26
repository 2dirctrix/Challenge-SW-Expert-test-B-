#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int end;
	int cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};
vector<Edge> edge[100000];
vector<int> dist(1000, 21e8);

void dijk(int st) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.emplace(st,0);
	dist[st] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (now.cost > dist[now.end])continue;
		for (auto cur : edge[now.end]) {
			int next_cost = cur.cost + now.cost;
			if (next_cost < dist[cur.end]) {
				dist[cur.end] = next_cost;
				pq.emplace(cur.end,next_cost);
			}
		}

	}
}
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].emplace_back(b, c);
		edge[b].emplace_back(a, c);
	}
	int a, b;
	cin >> a >> b;
	dijk(b);

	vector<int> path;
	int x = a;
	while (x != b && x!=0) {
		path.emplace_back(x);
		int next_node = 0;
		for (int i = 1; i <= n; i++) {
			for (auto& cur_edge : edge[x]) {
				if (cur_edge.end == i) {
					// 최종 비용= 현재에서 다음노드 비용+다음노드에서 최종노드 비용
					if (dist[x] == cur_edge.cost + dist[i]) {
						next_node = i;
						goto found;
					}
				}
			}
		}
	found:
		x = next_node;
	}

	path.emplace_back(b);
	cout << dist[a]<<endl;
	for (int node : path) {
		cout << node << ' ';
	}


	return 0;
}