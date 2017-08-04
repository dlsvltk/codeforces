#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string input;

int p[5001][5001];
int d[5001][5001];
int cnt[5001];

int isPalindrome(int s, int e) {
	if (e < s) return 0;
	if (e - s <= 1) {
		if (input[s] == input[e]) return true;
		return false;
	}

	int& ret = p[s][e];
	if (ret != -1) return ret;
	ret = 0;
	if (input[s] == input[e] && isPalindrome(s + 1, e - 1)) ret = 1;
	return ret;
}


int kthPalindrome(int s, int e) {
	int& ret = d[s][e];
	if (ret != -1) return ret;
	ret = 0;
	if (isPalindrome(s, e)) {
		int mid = (e - s + 1) / 2;
		ret = kthPalindrome(s, s + mid - 1) + 1;
	}
	return ret;
}
int main() {
	memset(p, -1, sizeof(p));
	memset(d, -1, sizeof(d));
	cin >> input;
	int sz = input.size();

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cnt[kthPalindrome(i, j)]++;
		}
	}

	for (int i = sz; i >= 0; i--) {
		cnt[i] += cnt[i + 1];
	}

	for (int i = 1; i <= sz; i++) {
		cout << cnt[i] << ' ';
	}
}
