// 백준 1541
// 최소값을 만드는 괄호 배치 찾기

// 입력
// 100-40+50+74-30+29-45+43+11

// 출력
// -222

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter);
int sum(string str);

int main()
{
    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');

    for (int i = 0; i < str.size(); i++)
    {
        int temp = sum(str[i]);
        if (i == 0)
        {
            answer = answer + temp;
        }
        else
        {
            answer = answer - temp;
        }
    }
    cout << answer << endl;
}

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter))
    {
        result.push_back(splitdata);
    }
    return result;
}

int sum(string str)
{
    int sum = 0;
    vector<string> temp = split(str, '+');

    for (int i = 0; i < temp.size(); i++)
    {
        sum += stoi(temp[i]);
    }
    return sum;
}