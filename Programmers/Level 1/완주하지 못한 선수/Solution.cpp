#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string>athlete;
    int idx = 0;
    for (idx = 0; idx < participant.size(); ++idx)
        athlete.insert(participant[idx]);

    for (idx = 0; idx < completion.size(); ++idx)
        athlete.erase(athlete.find(completion[idx]));

    return *athlete.begin();

}