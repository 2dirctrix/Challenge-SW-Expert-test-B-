#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int end;
    int cost;
    Edge(int a, int b) :end(a), cost(b) {}
};

struct cmp {
    bool operator()(Edge a, Edge b) {
        return a.cost > b.cost;
    }
};

int n, m;
vector<Edge> edge[100001];
vector<int> dist(1001,21e8);
vector<int> path(1001, -1);
void dijk(int st) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.emplace(st,0);
    dist[st] = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (now.cost > dist[now.end])continue;
        for (int i = 0; i < edge[now.end].size(); i++) {
            Edge cur = edge[now.end][i];
            int next_cost = now.cost + cur.cost;
            if (next_cost < dist[cur.end]) {
                dist[cur.end] = next_cost;
                path[cur.end] = now.end;
                pq.emplace(cur.end,next_cost);
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
        edge[a].emplace_back(b,c);
        edge[b].emplace_back(a, c);
    }
    int A, B;
    cin >> A >> B;

    dijk(A);
    cout << dist[B]<<endl;

    vector<int> revPath;
    int current = B;
    while (current != -1) {
        revPath.emplace_back(current);
        if (current == A)break;
        current = path[current];
    }
    reverse(revPath.begin(), revPath.end());
    for (int x : revPath) {
        cout << x << ' ';
    }
    return 0;
}