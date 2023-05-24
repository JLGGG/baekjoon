// 백준 1717
// 집합 표현하기

// 입력
// 7 8 원소 개수, 질의 개수
// 0 1 3
// 1 1 7
// 0 7 6
// 1 7 1
// 0 3 7
// 0 4 2
// 0 1 1
// 1 1 1

// 출력
// No
// No
// Yes

// 유니온 파인드 사용

#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int question, a, b;
        cin >> question >> a >> b;

        if (question == 0)
        {
            unionfunc(a, b);
        }
        else
        {
            if (checkSame(a, b))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

void unionfunc(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        parent[b] = a;
    }
}

int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}

bool checkSame(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        return true;
    }
    return false;
}