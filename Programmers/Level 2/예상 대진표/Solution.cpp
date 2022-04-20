#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int idx(0);


    queue<pair<int, int>>q;

    for (idx = 0; idx < n; ++idx) {
        q.push({ idx + 1,1 });
    }
    int num1(0), num2(0);
    int cnt(1);
    while (1) {
        num1 = q.front().first;
        cnt = q.front().second;
        q.pop();
        num2 = q.front().first;
        q.pop();
        if (num1 == a && num2 == b) {
            return cnt;
        }
        else if (num1 == a || num1 == b) {
            q.push({ num1, cnt + 1 });
        }
        else {
            q.push({ num2, cnt + 1 });
        }
    }

    return answer;
}