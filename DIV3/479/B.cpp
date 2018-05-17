#include<bits/stdc++.h>
using namespace std;
char s[101];
int c[26][26];
int main(){
	int n, a, b, m = 0;
	
	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; ++i){
		c[s[i] - 'A'][s[i+1] - 'A']++;
	}
	for (int i = 0; i < 26; ++i){
		for (int j = 0; j < 26; ++j){
			if (m < c[i][j]){
				m = c[i][j];
				a = i;
				b = j;
			}
		}
	}
	cout << char(a + 'A') << char(b + 'A');

	return 0;
}
