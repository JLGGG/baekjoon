// 백준 1920
// 원하는 정수 찾기

// 입력
// 5 데이터 개수 (1 <= N <= 100,000)
// 4 1 5 2 3
// 5 찾아야 할 숫자 개수
// 1 3 7 9 5

// 출력
// 1
// 1
// 0
// 0
// 1

// 이진탐색 사용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        bool find = false;
        int target;
        cin >> target;

        int start = 0;
        int end = A.size() - 1;

        while (start <= end)
        {
            int midi = (start + end) / 2;
            int midv = A[midi];

            if (midv > target)
            {
                end = midi - 1;
            }
            else if (midv < target)
            {
                start = midi + 1;
            }
            else
            {
                find = true;
                break;
            }
        }

        if (find)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}