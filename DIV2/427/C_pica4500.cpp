#include<iostream>
#include<algorithm>
using namespace std;

int cache[101][101][11];

int n, q, c;

int main() {
	cin >> n >> q >> c;

	for (int i = 0; i < n; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		for (int j = 0; j <= c; j++) {
			cache[x][y][j] += ((s + j) % (c + 1));
		}
	}

	for (int z = 0; z <= c; z++) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cache[i][j][z] += cache[i - 1][j][z] + cache[i][j - 1][z] - cache[i - 1][j - 1][z];
			}
		}
	}

	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= (c + 1);

		cout << cache[x2][y2][t] - cache[x2][y1 - 1][t] - cache[x1 - 1][y2][t] + cache[x1 - 1][y1 - 1][t] << endl;
	}
}
