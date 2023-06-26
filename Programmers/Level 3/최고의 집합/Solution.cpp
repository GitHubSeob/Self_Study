#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s)
        return { -1 };
    n++;
    while (--n) {
        answer.push_back(s / n);
        s -= s / n;
    }

    return answer;
}