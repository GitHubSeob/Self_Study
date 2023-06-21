#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int>score;

char type(char A, char B) {
    if (score[A] >= score[B]) {
        return A;
    }
    else if (score[A] < score[B]) {
        return B;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int idx(0);

    for (idx = 0; idx < survey.size(); ++idx) {
        if (choices[idx] <= 3) {
            score[survey[idx][0]] += (4 - choices[idx]);
        }
        else if (choices[idx] > 4) {
            score[survey[idx][1]] += (choices[idx] - 4);
        }
    }

    answer += type('R', 'T');
    answer += type('C', 'F');
    answer += type('J', 'M');
    answer += type('A', 'N');

    return answer;
}