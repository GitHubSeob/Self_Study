#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int idx(0), year(0), month(0), day(0), sum(0), i_today(0);
    char alp(' ');
    vector<int> answer;
    unordered_map<char, int>period;

    for (idx = 0; idx < terms.size(); ++idx) {
        period[terms[idx][0]] = stoi(terms[idx].substr(2, terms[idx].size() - 1));
    }

    i_today = stoi(today.substr(0, 4)) * 12 * 28 
        + stoi(today.substr(5, 6)) * 28 
        + stoi(today.substr(8, 9));

    for (idx = 0; idx < privacies.size(); ++idx) {
        year = stoi(privacies[idx].substr(0, 4));
        month = stoi(privacies[idx].substr(5, 6));
        day = stoi(privacies[idx].substr(8, 9));

        alp = privacies[idx][11];

        sum = year * 12 * 28 
            + month * 28 
            + day - 1 
            + period[alp] * 28;

        if (i_today > sum) {
            answer.push_back(idx + 1);
        }
    }

    return answer;
}