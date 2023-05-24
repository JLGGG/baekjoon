// 백준 1516
// 게임 개발하기

// 입력
// 5 건물 종류 수
// 10 -1
// 10 1 -1
// 4 1 -1
// 4 3 1 -1
// 3 3 -1

// 출력
// 10
// 20
// 14
// 18
// 17

// 위상 정렬 사용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A;
    vector<int> indegree;
    vector<int> selfBuild;
    A.resize(N + 1);
    indegree.resize(N + 1);
    selfBuild.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> selfBuild[i];
        while (true)
        {
            int pre;
            cin >> pre;

            if (pre == -1)
            {
                break;
            }
            A[pre].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> queue;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            queue.push(i);
        }
    }
    vector<int> result;
    result.resize(N + 1);

    while (!queue.empty())
    {
        int now = queue.front();
        queue.pop();

        for (int next : A[now])
        {
            indegree[next]--;
            result[next] = max(result[next], result[now] + selfBuild[now]);
            if (indegree[next] == 0)
            {
                queue.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] + selfBuild[i] << endl;
    }
}