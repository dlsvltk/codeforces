#include<iostream>
using namespace std;

int n;
int index[50][50];

bool solve() {
	int cnt = 0;
	int resultCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (index[i][j] != 1) resultCnt++;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (index[i][j] != 1) {
				int r, c;
				for (int k = 0; k < n; k++) {
					if (k == j) continue;
					
					r = index[i][k];
					for (int l = 0; l < n; l++) {
						if (l == i) continue;
						c = index[l][j];
						if ((r + c) == index[i][j])
						{
							cnt++;
							goto Exit;
						}
					}
				}
			Exit:
				continue;
			}
		}
	}
	if (cnt == resultCnt) return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> index[i][j];
		}
	}

	if (solve()) {
		cout << "Yes";
	}
	else
		cout << "No";
}