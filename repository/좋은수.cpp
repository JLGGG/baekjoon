// 백준 1253
// 좋은 수 구하기

// 입력
// 10 수의 개수
// 1 2 3 4 5 6 7 8 9 10

// 출력
// 8

// 정렬 투 포인터 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort (A.begin(), A.end());
    int Result = 0;

    for (int k = 0; k < N; k++) {
        int find = A[k];
        int i = 0;
        int j = N - 1;

        while (i < j) {
            if (A[i] + A[j] == find) {
                if (i != k && j != k) {
                    Result++;
                    break;
                } else if (i == k) {
                    i++;
                } else if (j == k) {
                    j--;
                }
            } else if(A[i] + A[j] < find) {
                i++;
            } else {
                j--;
            }
        }
    }
    cout << Result << endl;
}