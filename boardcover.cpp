#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;
bool board[20][20];

bool boardcheck(vector <pair<int, int>> check, bool board[20][20], int height, int width, int x, int y, int newmm) {
	bool ischeck = true;
	for (int z = 0; z < 3; z++) {
		int newx = x + check[newmm+z].first;
		int newy = y + check[newmm+z].second;
		if (newx < 0 || newx >= height || newy < 0 || newy >= width) {
			ischeck = false;
		}
		else if (board[newx][newy] == true) {
			ischeck = false;
		}
	}
	return ischeck;
}

int boardcover(vector <pair<int,int>> check, bool board[20][20], int height, int width) {
	
	int x = -1;
	int y = -1;
	for (int j = 0; j < height; j++) {
		for (int q = 0; q < width; q++) {
			if (board[j][q] == false) {
				x = j;
				y = q;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) {
		return 1;
	}
	int result = 0;
	for (int m = 0; m < 4; m++) {
		int newmm = m * 3;
		if (boardcheck(check, board, height, width, x, y, newmm)){
			for (int h = 0; h < 3; h++) {
				board[x + check[newmm + h].first][y + check[newmm + h].second] = true;
			}

			result += boardcover(check, board, height, width);

			for (int h = 0; h < 3; h++) {
				board[x + check[newmm + h].first][y + check[newmm + h].second] = false;
			}
		}
	}
	return result;
}
int main() {
	int cases;
	cin >> cases;
	 
	for (int i = 0; i < cases; i++) {
		for (int k = 0; k < 20; k++) {
			memset(board[k], 0, sizeof(int)*20);
		}

		vector<pair<int, int>> check;
		check.push_back(make_pair(0, 0));
		check.push_back(make_pair(1, 0));
		check.push_back(make_pair(1, -1));
		check.push_back(make_pair(0, 0));
		check.push_back(make_pair(0, 1));
		check.push_back(make_pair(1, 1));
		check.push_back(make_pair(0, 0));
		check.push_back(make_pair(1, 1));
		check.push_back(make_pair(1, 0));
		check.push_back(make_pair(0, 0));
		check.push_back(make_pair(1, 0));
		check.push_back(make_pair(0, 1));

		int height, width;
		cin >> height >> width;

		for (int p = 0; p < height; p++) {
			for (int m = 0; m < width; m++) {
				char shape;
				cin >> shape;
				if (shape == '#') {
					board[p][m] = true;
				}
				else if (shape == '.') {
					board[p][m] = false;
				}
			}
		}
		cout << boardcover(check, board, height, width) << endl;
	}
}