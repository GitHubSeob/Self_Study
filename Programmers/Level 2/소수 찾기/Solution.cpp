#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
string snum;
set<int>s;
set<string>combi;

void DFS(int idx, string num) {
    if (idx == snum.size()) {
        if (!num.empty()) {
            s.insert(stoi(num));
        }
    }
    else {
        DFS(idx + 1, num);
        num += snum[idx];
        DFS(idx + 1, num);
    }
}

int solution(string numbers) {
    int answer = 0;
    int num(0), idx(0);

    sort(numbers.begin(), numbers.end());
    do {
        snum = "";
        for (idx = 0; idx < numbers.size(); ++idx) {
            snum += numbers[idx];
            combi.insert(snum);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));


    for (auto iter = combi.begin(); iter != combi.end(); ++iter) {
        snum = *iter;
        DFS(0, "");
    }
    answer = s.size();

    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        num = *iter;
        int div(0);
        if (num == 1 || num == 0) answer--;
        else {
            for (div = 2; div * div <= num; ++div) {
                if (num % div == 0) {
                    answer--;
                    break;
                }
            }
        }
    }
    return answer;
}