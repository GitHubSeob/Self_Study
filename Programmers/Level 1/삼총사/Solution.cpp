#include <string>
#include <vector>
using namespace std;

vector<int>num;
int answer;

void DFS(int x, int cnt, int sum) {
    if (cnt == 3) {
        if (sum == 0)
            answer++;
    }
    else if (x < num.size()) {
        DFS(x + 1, cnt, sum);
        DFS(x + 1, cnt + 1, sum + num[x]);
    }
}

int solution(vector<int> number) {
    num = number;
    DFS(0, 0, 0);
    return answer;
}