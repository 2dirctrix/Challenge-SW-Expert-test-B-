#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> MAP;
struct Edge {
    int y, x;
    int cost;
};
struct cmp {
    bool operator()(Edge a, Edge b) {
        return a.cost > b.cost;
    }
};
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int dijk() {
    priority_queue<Edge, vector<Edge>, cmp>pq;
    pq.push({ 0,0,1 });
    vector<vector<int>> dist(N, vector<int>(M, 21e8));
    dist[0][0] = 1;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (dist[now.y][now.x] < now.cost)continue;
        if (now.y == N - 1 && now.x == M - 1) return now.cost;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
            if (MAP[ny][nx] == 0)continue;
            int next_cost = now.cost + 1;
            if (next_cost < dist[ny][nx]) {
                dist[ny][nx] = next_cost;
                pq.push({ ny,nx,next_cost });
            }
        }
    }
    return -1;
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    N = maps.size();
    M = maps[0].size();
    MAP = maps;
    answer = dijk();
    return answer;
}