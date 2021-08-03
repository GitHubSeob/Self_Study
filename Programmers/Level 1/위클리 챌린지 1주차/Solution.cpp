using namespace std;

int solution(int price, int money, int count)
{
    int answer = 0;

    for (count; count > 0; --count) {
        answer += price * count;
    }

    if (answer > money) answer -= money;
    else answer = 0;

    return answer;
}