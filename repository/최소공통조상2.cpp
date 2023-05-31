// 백준 11438
// 입력
// 15 노드 개수
// 1 2
// 1 3
// 2 4
// 3 7
// 6 2
// 3 8
// 4 9
// 2 5
// 5 11
// 7 13
// 10 4
// 11 15
// 12 5
// 14 7
// 6 질의 개수
// 6 11
// 10 9
// 2 6
// 7 6
// 8 13
// 8 15

// 출력
// 2
// 4
// 2
// 1
// 3
// 1

// 제곱수 형태의 최소 공통 조상 사용
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static int kmax;
static int parent[21][100001];
static vector<bool> visited;
int executeLCA(int a, int b);
void BFS(int node);

int main() {
    cin >> N;
    tree.resize(N+1);

    for (int i=0; i<N-1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    depth.resize(N+1);
    visited.resize(N+1);
    int temp = 1;
    kmax = 0;

    while (temp <= N) {
        temp <<= 1;
        kmax++;
    }

    BFS(1);

    for(int k=1; k<=kmax; k++) {
        for (int n=1; n<=N; n++) {
            parent[k][n] = parent[k-1][parent[k-1][n]];
        }
    }

    cin >> M;

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        int LCA = executeLCA(a, b);
        cout << LCA << endl;
    }
}

int executeLCA(int a, int b) {
    if (depth[a] > depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int k=kmax; k>=0; k--) {
        if (pow(2, k) <= depth[b] - depth[a]) {
            if (depth[a] <= depth[parent[k][b]]) {
                b = parent[k][b];
            }
        }
    }
    for (int k=kmax; k>=0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    int LCA = a;

    if (a!=b) {
        LCA = parent[0][LCA];
    }

    return LCA;
}

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    int level = 1;
    int now_size = 1;
    int count = 0;

    while (!myqueue.empty()) {
        int now_node = myqueue.front(); myqueue.pop();
        for (int next : tree[now_node]) {
            if (!visited[next]) {
                visited[next] = true;
                myqueue.push(next);
                parent[0][next] = now_node;
                depth[next] = level;
            }
        }
        count++;
        if (count==now_size) {
            count = 0;
            now_size = myqueue.size();
            level++;
        }
    }
}