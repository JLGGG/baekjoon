// 백준 13251
// 입력
// 3 색 종류
// 5 6 7 색깔별 조약돌 개수
// 2 k

// 출력
// 0.300653595

// DP 사용
#include<iostream>
using namespace std;

static int M, K, T;
static int D[51];
static double probability[51];
static double ans = 0.0;

int main() {
    cin >> M;

    for (int i=0; i<M; i++) {
        cin >> D[i];
        T += D[i];
    }

    cin >> K;

    for (int i=0; i<M; i++) {
        if (D[i] >= K) {
            probability[i] = 1.0;

            for (int k=0; k<K; k++) {
            probability[i] *= (double)(D[i] - k) / (T-k);
            }
        }        
        ans += probability[i];
    }
    cout << fixed;
    cout.precision(9);
    cout << ans;
}