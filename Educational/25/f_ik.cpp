//ik_e version

#include<bits/stdc++.h>
using namespace std;
int clen[8002];
int prefix[8002];
// int to string
int nl(int n) {
	int c = 0;
	while (n != 0) {
		n /= 10;
		c++;
	}
	return c;
}
char s[8001];
// prefix compute from idx to length by KMP
// this meaning is length of prefix = from idx to k
void fun_pre(int idx) {
	memset(prefix, 0, sizeof(prefix));
	prefix[idx] = 0;
	for (int i = idx, j = idx+1; s[j] != 0; j++) {
		while (i > idx && s[i] != s[j]) i = prefix[i-1]+idx;
		if (s[i] == s[j]) prefix[j] = (++i-idx);
	}
}

int main() {
	cin >> s;
	
	int l=0;
	while (s[l] != 0)l++;
	for (int i = 1; i <= l; i++) clen[i] = 10000; //clen[i] = length of compression string (length i)  
	int i;
	for (i = 0; i < l; i++) {
		fun_pre(i);
		for (int j = i+1; j<=l; j++) {
			//clen[j] = clen[i-1] + re
			int t = (j - i - prefix[j-1]);  //period t
			if ((j - i) % t == 0)           //exist period
				clen[j] = min(clen[j], clen[i] + nl((j - i) / t) + t);
			clen[j] = min(clen[j], clen[i] + j - i + 1);
		}
	}
	cout << clen[l];
	return 0;
}
