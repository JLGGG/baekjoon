// 백준 1929
// 소수 구하기

// 입력
// 3 16

// 출력
// 3
// 5
// 7
// 11
// 13

// 에라토스테네스 체 사용

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> A(N + 1);

    for (int i = 2; i <= N; i++)
    {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (A[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j <= N; j = j + i)
        {
            A[j] = 0;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (A[i] != 0)
        {
            cout << A[i] << endl;
        }
    }
}