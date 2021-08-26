#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<int>score(5, 0);
    vector<vector<string>>score_table(5, vector<string>(0, ""));
    vector<string>name = { "SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME" };

    int idx = 0;
    int idx2 = 0;
    string buffer = "";

    for (idx = 0; idx < 5; ++idx) {
        stringstream ss(table[idx]);
        int cnt = 0;
        while (ss >> buffer) {
            for (idx2 = 0; idx2 < languages.size(); ++idx2) {
                if (buffer == languages[idx2]) {
                    score[idx] += (preference[idx2] * (6 - cnt));
                }
            }
            cnt++;
        }
    }
    int max_score = 0;
    int max_idx = 0;
    for (idx = 0; idx < 5; ++idx) {
        if (score[idx] > max_score) {
            max_score = score[idx];
            max_idx = idx;
        }
        else if (score[idx] == max_score)
            if (name[idx].compare(name[max_idx]) < 0)
                max_idx = idx;
    }

    return name[max_idx];
}