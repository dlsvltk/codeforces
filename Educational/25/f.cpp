#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
string input;

int failure[8001][8001];
int digit[8001];
int cache[8001];

//모든 서픽스들에 대해서 failure Function을 구한다.
void make_failure() {
	for (int k = 0; k < n; k++) {
		string suffix = input.substr(k);
		int suffixSize = suffix.size();

		for (int i = 1, j = 0; i < suffixSize; i++) {
			while (j > 0 && suffix[i] != suffix[j]) j = failure[k][j - 1];
			if (suffix[i] == suffix[j]) failure[k][i] = ++j;
		}
	}
}

//어떤 숫자가 몇자리인지 미리 계산
void calc_digit() {
	for (int i = 1; i <= 8000; i++) {
		if (i >= 1 && i < 10) digit[i] = 1;
		else if (i >= 10 && i <= 99) digit[i] = 2;
		else if (i >= 100 && i <= 999) digit[i] = 3;
		else digit[i] = 4;
	}
}

int main() {
	memset(cache, 0x1f, sizeof(cache));
	calc_digit();
	cin >> input;
	n = input.size();

	make_failure();

	cache[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int len = j - i;
			int patternLen = (len - failure[i][len - 1]);//주기
			if (len % patternLen != 0) patternLen = len;//반복되는지 확인 반복되려면 2배, 3배, 4배 등이 되어야하므로 %했을때 당연히 0이 되어야 한다.
			int c = len / patternLen;//몇번 반복

			int unit = digit[c] + patternLen;
			cache[j] = min(cache[j], cache[i] + unit);
		}
	}

	cout << cache[n];
}
