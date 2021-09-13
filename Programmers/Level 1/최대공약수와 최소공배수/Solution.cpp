#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Getgcd(int a, int b) {
    int temp = 0;
    while (1) {
        if (a % b == 0) return b;
        else {
            temp = b;
            b = a % b;
            a = temp;
        }
    }
}

int Getlcm(int a, int b, int gcd) {
    return a * b / gcd;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int num = Getgcd(max(n, m), min(n, m));
    answer.push_back(num);
    answer.push_back(Getlcm(n, m, num));
    return answer;
}