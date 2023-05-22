// 백준 2751
// 수 정렬

// 입력 (1 <= N <= 1,000,000)
// 5 수의 개수
// 5
// 4
// 3
// 2
// 1

// 출력
// 1
// 2
// 3
// 4
// 5

// 병합 정렬 사용

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int s, int e);
static vector<int> A;
static vector<int> tmp;

int main() {
    int N;
    cin >> N;
    A = vector<int>(N+1, 0);
    tmp = vector<int>(N+1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    mergeSort(1, N);

    for (int i = 1; i <= N; i++) {
        cout << A[i] << endl;
    }
}

void mergeSort(int s, int e) {
    if (e - s < 1) {
        return;
    }

    int m = s + (e - s) / 2;
    mergeSort(s, m);
    mergeSort(m+1, e);

    for (int i = s; i <= e; i++) {
        tmp[i] = A[i];
    }

    int k = s;
    int index1 = s;
    int index2 = m+1;

    while (index1 <= m && index2 <= e) {
        if (tmp[index1] > tmp[index2]) {
            A[k] = tmp[index2];
            k++;
            index2++;
        }
        else {
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }

    while (index1 <= m) {
        A[k] = tmp[index1];
        k++;
        index1++;
    }

    while (index2 <= e) {
        A[k] = tmp[index2];
        k++;
        index2++;
    }

}