#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct E {
    int end, weight;

    E(int end, int weight) : end(end), weight(weight) {}

    bool operator<(const E& other) const {
        return weight > other.weight;
    }
};

unordered_map<int, int> id2idx;
vector<vector<E>> fwdList, revList;
int Num;

vector<int> dijkstra(const vector<vector<E>>& fwdList, int mHub) {
    int X = id2idx[mHub];
    vector<bool> visit(Num, false);
    vector<int> distance(Num, INT_MAX);

    priority_queue<E> pq;
    pq.emplace(X, 0);
    distance[X] = 0;

    while (!pq.empty()) {
        E curNode = pq.top();
        pq.pop();
        int cur = curNode.end;

        if (visit[cur]) continue;
        visit[cur] = true;

        for (const E& n : fwdList[cur]) {
            if (distance[n.end] > distance[cur] + n.weight) {
                distance[n.end] = distance[cur] + n.weight;
                pq.emplace(n.end, distance[n.end]);
            }
        }
    }

    return distance;
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    id2idx.clear();
    int idx = 0;

    // index 압축 과정
    for (int i = 0; i < N; i++) {
        if (id2idx.find(sCity[i]) == id2idx.end())
            id2idx[sCity[i]] = idx++;
        if (id2idx.find(eCity[i]) == id2idx.end())
            id2idx[eCity[i]] = idx++;
    }
    Num = id2idx.size();

    fwdList.resize(Num);
    revList.resize(Num);

    for (int i = 0; i < Num; i++) {
        fwdList[i].clear();
        revList[i].clear();
    }

    for (int i = 0; i < N; i++) {
        // 정방향 그래프 구성
        fwdList[id2idx[sCity[i]]].emplace_back(id2idx[eCity[i]], mCost[i]);
        // 역방향 그래프 구성
        revList[id2idx[eCity[i]]].emplace_back(id2idx[sCity[i]], mCost[i]);
    }

    return Num;
}

void add(int sCity, int eCity, int mCost) {
    // 정방향 그래프에 간선 추가하기
    fwdList[id2idx[sCity]].emplace_back(id2idx[eCity], mCost);

    // 역방향 그래프에 간선 추가하기
    revList[id2idx[eCity]].emplace_back(id2idx[sCity], mCost);
}

int cost(int mHub) {
    // mHub 에서 모든 정점까지의 최단 거리
    vector<int> distance = dijkstra(fwdList, mHub);
    // 모든 정점에서 mHub 까지의 최단 거리
    vector<int> revdistance = dijkstra(revList, mHub);

    int sum = 0;
    for (int i = 0; i < Num; i++) {
        sum += distance[i];
        sum += revdistance[i];
    }

    return sum;
}