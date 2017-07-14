#include<bits/stdc++.h>
using namespace std;

int one, two, two2, n;

int ans;

int main() {
	cin >> n >> one >> two;
	two *= 2;

	for (int i = 0; i < n; i++) {
		int come;
		cin >> come;
		if (come == 1) {
			if (one) {
				one--;
			}
			else if(two){
					two -= 2;
					two2++;
			}
			else if (two2) {
				two2--;
			}
			else {
				ans++;
			}
		}
		else if (come == 2) {
			if (two >= 2) {
				two -= 2;
			}
			else {
				ans += 2;
			}
		}
	}
	cout << ans;
	return 0;
}
