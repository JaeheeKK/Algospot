#include <iostream>
#include <cstring>

using namespace std;
bool arefriends[10][10];

int metfriends(bool notmet[10], int people) {
	int firstmet = -1;
	for (int n = 0; n < people; n++) {
		if (!notmet[n]) {
			firstmet = n;
			break;
		}
	}
	if (firstmet == -1) {
		return 1;
	}
	int result = 0;
	for (int m = firstmet + 1; m < people; m++) {
		if (!notmet[m] && arefriends[firstmet][m]) {
			notmet[firstmet] = true;
			notmet[m] = true;

			result += metfriends(notmet, people);

			notmet[firstmet] = false;
			notmet[m] = false;
		}
	}
	return result;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int people, friends;
		cin >> people >> friends;

		bool *notmet = new bool[people];
		memset(notmet, 0, sizeof(notmet));

		for (int k = 0; k < 10; k++) {
			memset(arefriends[k], 0, sizeof(bool)*10);
		}
		for (int k = 0; k < friends; k++) {
			int friendA, friendB;
			cin >> friendA >> friendB;
			arefriends[friendA][friendB] = true;
			arefriends[friendB][friendA] = true;
		}

		cout << metfriends(notmet, people) << endl;
	}
}