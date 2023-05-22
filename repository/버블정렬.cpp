// 벡준 2750
// 버블 정렬

// 입력
// 5 수의 개수
// 5
// 2
// 3
// 4
// 1

// 출력
// 1
// 2
// 3
// 4
// 5

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << endl;
    }
}