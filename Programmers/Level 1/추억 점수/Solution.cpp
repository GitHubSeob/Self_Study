#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size(), 0);
    int idx(0), idx2(0);
    unordered_map<string, int>score;
    for (idx = 0; idx < name.size(); ++idx) {
        score[name[idx]] = yearning[idx];
    }
    for (idx = 0; idx < photo.size(); ++idx) {
        for (idx2 = 0; idx2 < photo[idx].size(); ++idx2) {
            answer[idx] += score[photo[idx][idx2]];
        }
    }
    return answer;
}