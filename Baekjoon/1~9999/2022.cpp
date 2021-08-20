#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x = 0, y = 0, c = 0;
	cin >> x >> y >> c;
	double left = 0, right = min(x, y);
	while (right - left >= 1e-3) {
		double width = (left + right) / 2;
		double height1 = sqrt(pow(x, 2) - pow(width, 2));
		double height2 = sqrt(pow(y, 2) - pow(width, 2));
		double num = height1 * height2 / (height1 + height2);

		if (num < c)
			right = width;
		else left = width;
	}
	cout << fixed;
	cout.precision(3);
	cout << right;
}

//문제풀이: https://githubseob.tistory.com/49