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

//��� ���Ƚ��鿡 ���ؼ� failure Function�� ���Ѵ�.
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

//� ���ڰ� ���ڸ����� �̸� ���
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
			int patternLen = (len - failure[i][len - 1]);//�ֱ�
			if (len % patternLen != 0) patternLen = len;//�ݺ��Ǵ��� Ȯ�� �ݺ��Ƿ��� 2��, 3��, 4�� ���� �Ǿ���ϹǷ� %������ �翬�� 0�� �Ǿ�� �Ѵ�.
			int c = len / patternLen;//��� �ݺ�

			int unit = digit[c] + patternLen;
			cache[j] = min(cache[j], cache[i] + unit);
		}
	}

	cout << cache[n];
}
