#include <iostream>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int borrow, team;
		double answer, result = 0.0;
		cin >> borrow >> team;
		int *price = new int[borrow];
		for (int j = 0; j < borrow; j++) {
			cin >> price[j];
			result += price[j];
		}
		for (int j = team; j <= borrow; j++) {
			for (int k = j; k <= borrow; k++) {
				answer = 0;
				for (int m = (k - 1); m >= k - j; m--) {
					answer += price[m];
				}
				answer /= j;
				if (result > answer) {
					result = answer;
				}
			}
		}
		printf("%.10lf\n", result);
	}
}