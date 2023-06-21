#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = { 50,50,0,0 };
    int y(0), x(0);
    for (y = 0; y < wallpaper.size(); ++y) {
        for (x = 0; x < wallpaper[y].size(); ++x) {
            if (wallpaper[y][x] == '#') {
                answer[0] = min(answer[0], y);
                answer[1] = min(answer[1], x);
                answer[2] = max(answer[2], y + 1);
                answer[3] = max(answer[3], x + 1);
            }
        }
    }
    return answer;
}