//ik_e version
//implementation O(nk)
#include<bits\stdc++.h>
using namespace std;

int p[105];
bool exist[105];
int main(){
	int n, m,pre,l;
	bool chk = 1;
	cin >> n >> m;
	cin >> pre;
	for (int i = 1; i < m; i++){
		cin >> l;
		int len = (l - pre + n) % n;
		if (len == 0) len = n;
		if ((exist[len] || p[pre] != 0 )&& p[pre] != len){
			chk = 0;
			break;
		}
		exist[len] = 1;
		p[pre] = len;
		pre = l;
	}

	if (chk){
		for (int i = 1; i <= n; i++){
			if (p[i] == 0){
				int k = 1;
				while (exist[k]) k++;
				p[i] = k;
				exist[k] = 1;
			}
		}
		for (int i = 1; i <= n; i++) cout << p[i] << " ";
	}
	else cout << "-1";
	return 0;
}
