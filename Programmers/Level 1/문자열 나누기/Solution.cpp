#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char start(' ');
    int X(0), notX(0), idx(0);

    for (idx = 0; idx < s.size(); ++idx) {
        if (start == ' ') {
            start = s[idx];
        }
        if (start == s[idx]) {
            X++;
        }
        else {
            notX++;
        }
        if (X != 0 && X == notX) {
            answer++;
            X = 0;
            notX = 0;
            start = ' ';
        }
    }
    if (X != 0) {
        answer++;
    }

    return answer;
}