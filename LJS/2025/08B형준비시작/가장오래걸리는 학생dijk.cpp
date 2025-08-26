#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int end;
    int cost;
    Edge(int e, int c) : end(e), cost(c) {}
};
struct cmp {
    bool operator()(Edge a,Edge b) {
        return a.cost > b.cost;
    }
};
int n, m;
vector<Edge> edge[100000];
vector<int> dist(100000, 21e8);
void dijk(int st) {
    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.emplace(st,0);
    dist[st] = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (now.cost > dist[now.end])continue;
        for (int i = 0; i<edge[now.end].size(); i++) {
            int cur_cost = edge[now.end][i].cost;
            int cur_end = edge[now.end][i].end;
            int next_cost = cur_cost + now.cost;
            if (dist[cur_end] > next_cost) {
                dist[cur_end] = next_cost;
                pq.emplace(cur_end,next_cost);
            }

        }
    }
}



int main() {
    // Please write your code here.
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[b].emplace_back(a,c);
    }
    dijk(n);
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        Max=max(dist[i],Max);
    }
    cout << Max;
    return 0;
}