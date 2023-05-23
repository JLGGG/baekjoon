// 백준 11659
// 구간 합

// 입력
// 5 3 데이터의 개수, 질의 개수
// 5 4 3 2 1
// 1 3
// 2 4
// 5 5

// 출력
// 12
// 9
// 1

#include <iostream>
using namespace std;

int main()
{
    int data_num, quize_num;
    cin >> data_num >> quize_num;
    int S[100001] = {};

    // 구간 합에서는 인덱스 항상 1부터 시작
    for (int i = 1; i <= data_num; i++)
    {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    for (int i = 0; i < quize_num; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << endl;
    }
}