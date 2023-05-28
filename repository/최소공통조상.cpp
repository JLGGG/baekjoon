// 백준 11437
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

// 최소 공통 조상 구하기 방법 사용
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;
int executeLCA(int a, int b);

void BFS(int node);

int main() {
    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);
    visited.resize(N+1);

    for (int i=0; i<N-1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        int LCA = executeLCA(a, b);
        cout << LCA << endl;
    }
}

int executeLCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (depth[a] != depth[b]) {
        a = parent[a];
    }
    while (a!=b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    int level = 1;
    int now_size = 1;
    int count = 0;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (int next : tree[now_node]) {
            if (!visited[next]) {
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
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