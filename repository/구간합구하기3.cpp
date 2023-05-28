// 백준 2042
// 입력
// 5 2 2
// 1
// 2
// 3
// 4
// 5
// 1 3 6
// 2 2 5
// 1 5 2
// 2 3 5

// 출력
// 17
// 12

// 세그먼트 트리 사용
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int treeHeight = 0;
    int length = N;

    while(length != 0) {
        length /= 2;
        treeHeight++;
    }
    int treeSize = int(pow(2, treeHeight + 1));
    int leftNodeStartIndex = treeSize / 2 - 1;
    tree.resize(treeSize + 1);

    for (int i=leftNodeStartIndex+1; i<=leftNodeStartIndex + N; i++) {
        cin >> tree[i];
    }
    setTree(treeSize - 1);

    for (int i=0; i<M+K; i++) {
        long a, s, e;
        cin >> a >> s >> e;

        if (a==1) {
            changeVal(leftNodeStartIndex + s, e);
        } else if (a==2) {
            s = s + leftNodeStartIndex;
            e = e + leftNodeStartIndex;
            cout << getSum(s, e) << endl;
        }
    }
}

long getSum(int s, int e) {
    long partSum = 0;

    while (s<=e) {
        if (s%2==1) {
            partSum = partSum + tree[s];
            s++;
        } else if (e % 2 == 0) {
            partSum = partSum + tree[e];
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partSum;
}

void changeVal(int index, long val) {
    long diff = val - tree[index];

    while (index > 0) {
        tree[index] = tree[index] + diff;
        index = index / 2;
    }
}

void setTree(int i) {
    while (i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}