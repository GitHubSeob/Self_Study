#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer(""), rev("");
    int sum(0), idx(0);
    for (idx = 1; idx < food.size(); ++idx) {
        if (food[idx] % 2 == 1) {
            food[idx] -= 1;
        }
        food[idx] /= 2;
        while (food[idx]--) {
            answer += (idx + '0');
        }
    }
    rev = answer;
    reverse(rev.begin(), rev.end());
    answer += '0';
    answer += rev;

    return answer;
}