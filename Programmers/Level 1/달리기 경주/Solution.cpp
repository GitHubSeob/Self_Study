#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    int idx(0), num(0), prev_num(0);
    string name(""), prev_name("");
    unordered_map<string, int>name_num;
    unordered_map<int, string>num_name;

    for (idx = 0; idx < players.size(); ++idx) {
        name_num.insert({ players[idx],idx + 1 });
        num_name.insert({ idx + 1,players[idx] });
    }

    for (idx = 0; idx < callings.size(); ++idx) {
        num = name_num[callings[idx]];
        name = num_name[num];
        prev_name = num_name[num - 1];
        prev_num = num - 1;

        name_num[prev_name]++;
        name_num[name]--;

        num_name[num] = prev_name;
        num_name[prev_num] = name;
    }

    for (idx = 1; idx <= players.size(); ++idx) {
        answer.push_back(num_name[idx]);
    }
    return answer;
}