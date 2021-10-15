#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for(int idx=1;idx<n;++idx)
        if(n%idx==1) return idx;
}