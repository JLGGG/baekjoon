// 백준 11003
// 최솟값 찾기

// 입력
// 12 3 숫자의 개수, 슬라이딩 윈도우의 크기
// 1 5 2 3 6 2 3 7 3 5 2 6

// 출력
// 1 1 1 2 2 2 2 2 3 3 2 2

// 슬라이딩 윈도우 사용

#include <iostream>
#include <deque>
using namespace std;
using Node = pair<int, int>;

int main()
{
    int N, L;
    cin >> N >> L;
    deque<Node> mydeque;

    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;

        while (mydeque.size() && mydeque.back().first > now)
        {
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now, i));

        if (mydeque.front().second <= i - L)
        {
            mydeque.pop_front();
        }
        cout << mydeque.front().first << ' ';
    }
}