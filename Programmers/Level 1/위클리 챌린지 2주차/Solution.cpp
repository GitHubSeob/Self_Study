#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector<int>sum(scores.size(), 0);
    vector<int>avg(scores.size(), 0);

    int y = 0, x = 0;
    for (x = 0; x < scores.size(); ++x) {
        int max_score = -1;
        int min_score = 101;
        for (y = 0; y < scores.size(); ++y) {
            if (y != x) {
                sum[x] += scores[y][x];
                max_score = max(max_score, scores[y][x]);
                min_score = min(min_score, scores[y][x]);
            }
        }
        if (scores[x][x]<min_score || scores[x][x]>max_score)
            avg[x] = sum[x] / (scores.size() - 1);
        else {
            sum[x] += scores[x][x];
            avg[x] = sum[x] / scores.size();
        }
    }

    for (x = 0; x < scores.size(); ++x) {
        if (avg[x] >= 90) answer.push_back('A');
        else if (avg[x] >= 80) answer.push_back('B');
        else if (avg[x] >= 70) answer.push_back('C');
        else if (avg[x] >= 50) answer.push_back('D');
        else answer.push_back('F');
    }

    return answer;
}
