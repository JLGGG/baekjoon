// 백준 1197
// 입력
// 3 3 노드 개수, 에지 개수
// 1 2 1
// 2 3 2
// 1 3 3

// 출력
// 3

// 최소 신장 트리 사용
#include<iostream>
#include<queue>
using namespace std;

void munion(int a, int b);
int find(int a);
static vector<int> parent;

using Edge = struct Edge {
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N+1);

    for(int i=1; i<=N; i++) {
        parent[i] = i;
    }
    for (int i=0; i<M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(Edge{s, e, v});
    }

    int useEdge = 0;
    int result = 0;

    while (useEdge < N-1) {
        Edge now = pq.top();
        pq.pop();
        if(find(now.s) != find(now.e)) {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    cout << result;
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a!=b) {
        parent[b] = a;
    }
}

int find(int a) {
    if (a==parent[a]) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}