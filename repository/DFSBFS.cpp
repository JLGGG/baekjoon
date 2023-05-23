// 백준 1260
// DFS와 BFS

// 입력
// 4 5 1 노드 개수, 에지 개수, 시작점
// 1 2
// 1 3
// 1 4
// 2 4
// 3 4

// 출력
// 1 2 4 3
// 1 2 3 4

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);

int main()
{
    int N, M, start;
    arrive = false;
    cin >> N >> M >> start;
    A.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N + 1, false);

    DFS(start);
    cout << endl;
    fill(visited.begin(), visited.end(), false);
    BFS(start);
    cout << endl;
}

void DFS(int node)
{
    cout << node << " ";
    visited[node] = true;

    for (int i : A[node])
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int f_node = q.front();
        q.pop();
        cout << f_node << " ";
        for (int i : A[f_node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}