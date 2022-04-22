#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int x(0), y(0);
    int idx(0);
    int sum(brown + yellow);
    vector<int>div;
    for (x = sum; x >= 1; --x) {
        if (sum % x == 0) {
            if (yellow == ((x - 2) * (sum / x - 2))) {
                answer[0] = x;
                answer[1] = sum / x;
                return answer;
            }
        }
    }
}