#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double x(0);    
    double fx(0);

    for(x=w;x>0;--x){
        fx=(double)h*x/(double)w*-1+(double)h;        
        answer+=int(floor(fx));
    }

    return answer*2;
}