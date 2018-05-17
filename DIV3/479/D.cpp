#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101];
int p[101];
int nxt[101];
int main(){
	int n, s;
	cin >> n;
	memset(p, -1, sizeof(p));
	memset(nxt, -1, sizeof(nxt));

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (i != j){
				if (a[i] * 3 == a[j]){
					p[i] = j;
					nxt[j] = i;
					break;
				}
				if (!(a[i] & 1) && a[i] >> 1 == a[j]){
					p[i] = j;
					nxt[j] = i;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i){
		if (p[i] == -1) s = i;
	}
	cout << a[s]<<" ";
	while (nxt[s] != -1){
		s = nxt[s];
		cout << a[s]<< " ";
	}
	return 0;
}
