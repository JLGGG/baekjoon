// 백준 11657

// 입력
// 3 4
// 1 2 4
// 1 3 3
// 2 3 -4
// 3 1 -2

// 출력
// -1

// 벨만포드 사용
#include<iostream>
#include<vector>
#include<limits.h>
#include<tuple>
using namespace std;

using edge = tuple<int, int, int>;
static int N, M;
static vector<long> mdistance;
static vector<edge> edges;

int main() {
    cin >> N >> M;
    mdistance.resize(N+1);
    std::fill(mdistance.begin(), mdistance.end(), LONG_MAX);

    for (int i=0; i<M; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }

    mdistance[1] = 0;

    for (int i=1; i<N; i++) {
        for (int j=0; j<M; j++) {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
                mdistance[end] = mdistance[start] + time;
            }
        }
    }
    bool mCycle = false;

    for (int i=0; i<M; i++) {
        edge medge = edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);

        if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
            mCycle = true;
        }
    }
    if(!mCycle) {
        for (int i=2; i<=N; i++) {
            if(mdistance[i] == LONG_MAX) {
                cout << -1 << endl;
            } else {
                cout << mdistance[i] << endl;
            }
        }
    } else {
        cout << -1 << endl;
    }
}
