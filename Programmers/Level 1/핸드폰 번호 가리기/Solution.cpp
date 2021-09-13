#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int idx = 0;
    for (idx = 0; idx + 4 < phone_number.size(); ++idx)
        phone_number[idx] = '*';
    return phone_number;
}