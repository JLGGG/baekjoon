// 백준 1854
// 입력
// 5 10 2
// 1 2 2
// 1 3 7
// 1 4 5
// 1 5 6
// 2 4 2
// 2 3 4
// 3 4 6
// 3 5 8
// 5 2 4
// 5 4 1

// 출력
// -1
// 10
// 7
// 5 
// 14

// 다익스트라, 우선순위 큐 사용
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using Node = pair<int, int>;
static int N, M, K;
static int W[1001][1001];
static priority_queue<int> distQueue[1001];

int main() {
    cin >> N >> M >> K;

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        W[a][b] = c;
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));
    distQueue[1].push(0);

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();

        for (int adjNode = 1; adjNode <= N; adjNode++) {
            if (W[u.second][adjNode] != 0) {
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                } else if (distQueue[adjNode].top() > u.first + W[u.second][adjNode]) {
                    distQueue[adjNode].pop();
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }
    
    for (int i = 1; i<=N; i++) {
        if(distQueue[i].size() == K) {
            cout << distQueue[i].top() << endl;
        } else {
            cout << -1 << endl;
        }
    }
}