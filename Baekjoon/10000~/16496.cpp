#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin >> N;
    vector<string>Arr(N,"");
    int idx = 0;

    for (idx = 0; idx < N; ++idx)
        cin >> Arr[idx];

    sort(Arr.begin(), Arr.end(), Compare);
    if (Arr[0] == "0") cout << "0";
    else
        for (idx = 0; idx < Arr.size(); ++idx)
            cout << Arr[idx];
}

//문제풀이: https://githubseob.tistory.com/113