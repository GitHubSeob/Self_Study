#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>>log;
    map<string, string>user;
    string act(""), name(""), uid("");
    int idx(0);
    for (idx = 0; idx < record.size(); ++idx) {
        istringstream istr(record[idx]);
        istr >> act >> uid >> name;
        
        if (act != "Change")
            log.push_back({ act, uid });
    }
    for (idx = 0; idx < log.size(); ++idx) {
        if (log[idx].first == "Enter")
            answer.push_back(user[log[idx].second] + "님이 들어왔습니다.");
        else 
            answer.push_back(user[log[idx].second] + "님이 나갔습니다.");
    }
    return answer;
}