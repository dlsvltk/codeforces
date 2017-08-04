#include<iostream>
#include<vector>
using namespace std;

int n, m;

vector<int> r, c;

int board[101][101];

bool chkR(int r) {
	for (int i = 1; i <= m; i++) {
		if (board[r][i] < 1) return false;
	}
	return true;
}

bool chkC(int c) {
	for (int i = 1; i <= n; i++) {
		if (board[i][c] < 1) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	bool update = true;
	while (update) {
		update = false;
		if (m > n) {
			for (int i = 1; i <= n; i++) {
				if (chkR(i)) {
					r.push_back(i);
					update = true;
					for (int j = 1; j <= m; j++) {
						board[i][j]--;
					}
					goto Fin;
				}
			}
			for (int i = 1; i <= m; i++) {
				if (chkC(i)) {
					c.push_back(i);
					update = true;
					for (int j = 1; j <= n; j++) {
						board[j][i]--;
					}
					goto Fin;
				}
			}
		}
		else {
			for (int i = 1; i <= m; i++) {
				if (chkC(i)) {
					c.push_back(i);
					update = true;
					for (int j = 1; j <= n; j++) {
						board[j][i]--;
					}
					goto Fin;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (chkR(i)) {
					r.push_back(i);
					update = true;
					for (int j = 1; j <= m; j++) {
						board[i][j]--;
					}
					goto Fin;
				}
			}
		}
	Fin:
		continue;
	}

	bool result = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				result = false;
				goto Exit;
			}
		}
	}
Exit:
	if (!result) {
		cout << -1;
	}
	else {
		cout << r.size() + c.size() << endl;
		for (int i = 0; i < r.size(); i++) {
			cout << "row" << ' ' << r[i] << endl;
		}
		for (int i = 0; i < c.size(); i++) {
			cout << "col" << ' ' << c[i] << endl;
		}
	}
}
