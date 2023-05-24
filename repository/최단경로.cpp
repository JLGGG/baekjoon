// 백준 1753
// 최단 경로 구하기

// 입력
// 5 6
// 1
// 5 1 1
// 1 2 2
// 1 3 3
// 2 3 4
// 2 4 5
// 3 4 6

// 출력
// 0
// 2
// 3
// 7
// INF

// 다익스트라 사용
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

using edge = pair<int, int>;
static int V, E, K;
static vector<int> mdistance;
static vector<bool> visited;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
    cin >> V >> E >> K;
    mdistance.resize(V + 1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    q.push(make_pair(0, K));
    mdistance[K] = 0;

    while (!q.empty())
    {
        edge current = q.top();
        q.pop();
        int c_v = current.second;
        if (visited[c_v])
        {
            continue;
        }
        visited[c_v] = true;

        for (int i = 0; i < mlist[c_v].size(); i++)
        {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if (mdistance[next] > mdistance[c_v] + value)
            {
                mdistance[next] = mdistance[c_v] + value;
                q.push(make_pair(mdistance[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
        {
            cout << mdistance[i] << endl;
        }
        else
        {
            cout << "INF" << endl;
        }
    }
}