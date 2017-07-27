//ik_e version
//implementation - firstly desgin and later coding!
//O(n+m)
#include<bits\stdc++.h>
using namespace std;

struct sofa{
	int x1, y1, x2, y2;
};
sofa loc[100005];
int cx_l[100005], cx_r[100005];
int cy_t[100005], cy_b[100005];
int main(){
	int d, n, m, sol=0;
	int cl, cr, ct, cb;
	cin >> d;
	cin >> n >> m;
	for (int i = 0; i < d; i++){
		cin >> loc[i].x1 >> loc[i].y1 >> loc[i].x2 >> loc[i].y2;
		if (loc[i].x1 >loc[i].x2)	swap(loc[i].x1, loc[i].x2);
		if (loc[i].y1 > loc[i].y2)	swap(loc[i].y1, loc[i].y2);
		cx_l[loc[i].x1]++;
		cx_r[loc[i].x2]++;
		cy_t[loc[i].y1]++;
		cy_b[loc[i].y2]++;
	}
	for (int i = 1; i <= n; i++)	cx_l[i] += cx_l[i - 1];
	for (int i = n - 1; i; i--)		cx_r[i] += cx_r[i + 1];
	for (int i = 1; i <= m; i++)	cy_t[i] += cy_t[i - 1];
	for (int i = m - 1; i; i--)		cy_b[i] += cy_b[i + 1];

	cin >> cl >> cr >> ct >> cb;
	for (int i = 0; i < d; i++){
		int l, r, t, b;
		if (loc[i].x1 == loc[i].x2){
			l = cx_l[loc[i].x1-1];
			r = cx_r[loc[i].x1+1];
			t = cy_t[loc[i].y1]-1;
			b = cy_b[loc[i].y2]-1;
		}
		else{
			l = cx_l[loc[i].x1]-1;
			r = cx_r[loc[i].x2]-1;
			t = cy_t[loc[i].y1-1];
			b = cy_b[loc[i].y1+1];
		}
		
		if (cl == l && cr == r && ct == t && cb == b){
			sol = i + 1;
			break;
		}
	}


	if (sol == 0) cout << -1;
	else cout << sol;
	return 0;
}
