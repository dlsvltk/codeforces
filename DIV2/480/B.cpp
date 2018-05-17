#include<bits/stdc++.h>
using namespace std;

char s[101];

int main() {
	int n, k;
	cin >> n >> k;
	cout << "YES" << endl;
	memset(s, '.', n);
	if (k & 1) {
		for (int i = 0; i < n; ++i) 	cout << ".";
		cout << endl;
		for (int i = 1; i <= ((k+1) >> 2); ++i) {
			s[n / 2 + i] = '#';
			s[n / 2 - i] = '#';
		}

		cout << s << endl;
		s[n/2] = '#';
		if (k & 2) {
			s[n / 2 + 1] = '.';
			s[n / 2 - 1] = '.';
		}
		cout << s << endl;
		for (int i = 0; i < n; ++i) 	cout << ".";
	}
	else {
		for (int i = 0; i < n; ++i) 	cout << ".";
		cout << endl;
		for (int i = 0; i < (k>>1); ++i)	s[i + 1] = '#';
		cout << s << endl
			<< s << endl;

		for (int i = 0; i < n; ++i) 	cout << ".";
	}

	return 0;
}
