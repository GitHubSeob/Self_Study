#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int y(0), x(0), idx(0), move(0), cnt(0);
    char dir(' ');
    for (y = 0; y < park.size(); ++y) {
        for (x = 0; x < park[y].size(); ++x) {
            if (park[y][x] == 'S') {
                answer.push_back(y);
                answer.push_back(x);
            }
        }
    }
    for (idx = 0; idx < routes.size(); ++idx) {
        dir = routes[idx][0];
        cnt = routes[idx][2] - '0';
        move = cnt;
        if (dir == 'N') {
            y = -1;
            x = 0;
        }
        else if (dir == 'S') {
            y = 1;
            x = 0;
        }
        else if (dir == 'W') {
            y = 0;
            x = -1;
        }
        else if (dir == 'E') {
            y = 0;
            x = 1;
        }
        for (cnt; cnt > 0; --cnt) {
            if (answer[0] + y * cnt < 0 || park.size() <= answer[0] + y * cnt)
                break;
            if (answer[1] + x * cnt < 0 || park[0].size() <= answer[1] + x * cnt)
                break;
            if (park[answer[0] + y * cnt][answer[1]] == 'X')
                break;
            if (park[answer[0]][answer[1] + x * cnt] == 'X')
                break;
        }
        if (cnt == 0) {
            answer[0] += (y * move);
            answer[1] += (x * move);
        }

    }

    return answer;
}