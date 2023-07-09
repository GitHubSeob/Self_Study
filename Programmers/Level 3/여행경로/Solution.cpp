#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<bool>visited;
vector<vector<string>>ticket;
string answer("Z");
void DFS(string start, int cnt, string route) {
    int idx(0);

    for (idx = 0; idx < ticket.size(); ++idx) {
        if (visited[idx] == false) {
            if (start != ticket[idx][0]) continue;
            if (cnt + 1 == ticket.size()) {
                answer = min(answer, route + " " + ticket[idx][1]);
            }
            else {
                visited[idx] = true;
                DFS(ticket[idx][1], cnt + 1, route + " " + ticket[idx][1]);
                visited[idx] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    string country("");
    ticket = tickets;
    visited = vector<bool>(tickets.size(), false);
    vector<string>answer_v;
    int idx(0);
    string route("");

    route = "ICN ";
    for (idx = 0; idx < ticket.size(); ++idx) {
        if (tickets[idx][0] == "ICN") {
            visited[idx] = true;
            DFS(tickets[idx][1], 1, route + tickets[idx][1]);
            visited[idx] = false;
        }
    }

    istringstream iss(answer);

    while (getline(iss, country, ' ')) {
        answer_v.push_back(country);
    }

    return answer_v;
}