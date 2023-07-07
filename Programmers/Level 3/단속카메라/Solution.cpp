#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>car1, vector<int>car2) {
    if (car1[0] == car2[0]) {
        return car1[1] < car2[1];
    }
    return car1[0] < car2[0];
}

int solution(vector<vector<int>> routes) {
    int answer(0), idx(0), coord(-30001);
    sort(routes.begin(), routes.end(), cmp);

    for (idx = 0; idx < routes.size(); ++idx) {
        if (coord < routes[idx][0]) {
            coord = routes[idx][1];
            answer++;
        }
        else if (coord > routes[idx][1]) {
            coord = routes[idx][1];
        }
    }

    return answer;
}