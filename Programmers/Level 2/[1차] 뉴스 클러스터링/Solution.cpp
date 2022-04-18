#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int addmap(map<string, int>m1, map<string, int>m2) {
    int ret(0);
    for (auto iter = m1.begin(); iter != m1.end(); ++iter) {
        if (m2[iter->first] != 0) {
            m2[iter->first] = max(m2[iter->first], iter->second);
        }
        else {
            m2[iter->first] = iter->second;
        }
    }
    for (auto iter = m2.begin(); iter != m2.end(); ++iter) {
        ret += iter->second;
    }
    return ret;
}

int gyomap(map<string, int>m1, map<string, int>m2) {
    int ret(0);
    map<string, int>m3;
    for (auto iter = m1.begin(); iter != m1.end(); ++iter) {
        if (m2[iter->first] != 0) {
            m3[iter->first] = min(m2[iter->first], iter->second);
        }
    }
    for (auto iter = m3.begin(); iter != m3.end(); ++iter) {
        ret += iter->second;
    }
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int>m1;
    map<string, int>m2;
    int idx(0), idx2(0);
    int num1(0), num2(0);

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    string str("");
    for (idx = 0; idx + 1 < str1.size(); ++idx) {
        if (isalpha(str1[idx]) != 0 && isalpha(str1[idx + 1]) != 0) {
            str += str1[idx];
            str += str1[idx + 1];
            m1[str]++;
            str = "";
        }
    }
    for (idx2 = 0; idx2 + 1 < str2.size(); ++idx2) {
        if (isalpha(str2[idx2]) != 0 && isalpha(str2[idx2 + 1]) != 0) {
            str += str2[idx2];
            str += str2[idx2 + 1];
            m2[str]++;
            str = "";
        }
    }

    int gyo = gyomap(m1, m2);
    int hap = addmap(m1, m2);

    if (hap == 0) return 65536;
    else return gyo * 65536 / hap;

}