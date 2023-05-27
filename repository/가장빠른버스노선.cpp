//백준 11404

// 입력
// 5 
// 14
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3
// 3 5 10
// 3 1 8
// 1 4 2
// 5 1 7
// 3 4 2
// 5 2 4

// 출력
// 0 2 3 1 4
// 12 0 15 2 5
// 8 5 0 1 1
// 10 7 13 0 3
// 7 4 10 6 0

// 플로이드-워셜 사용
#include<iostream>
#include<limits.h>
using namespace std;

static int N, M;
static long mdistance[101][101];

int main() {
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i==j) {
                mdistance[i][j] = 0;
            } else {
                mdistance[i][j] = 10000001;
            }
        }
    }
    for (int i=0; i<M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        if (mdistance[s][e] > v) {
            mdistance[s][e] = v;
        }
    }
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (mdistance[i][j] == 10000001) {
                cout << "0 ";
            } else {
                cout << mdistance[i][j] << " ";
            }
        }
        cout << endl;
    }
}