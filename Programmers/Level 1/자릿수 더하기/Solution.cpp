#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string sn = to_string(n);
    int idx = 0;
    for (idx = 0; idx < sn.size(); ++idx)
        answer += sn[idx] - '0';
    return answer;
}