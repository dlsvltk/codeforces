//ik_e version
//O(n) by indexing 
//greedy - 1~i min cost store each length. so min cost+expand orderly
#include<bits\stdc++.h>
#define INF 2000000005
using namespace std;

vector<pair<unsigned, unsigned> > lefts[200005], rights[200005];
unsigned cost[200005];
int main(){
	int n, x,l,r,c;
	cin >> n >> x;
	for (int i = 0; i <= x; i++) cost[i] = INF;
	for (int i = 0; i < n; i++){
		cin >> l >> r >> c;
		lefts[l].push_back({ r,c });
		rights[r].push_back({ l,c });
	}
	unsigned len, sol=INF;
	for (int i = 1; i <= 200000; i++){
		for (int k = 0; k < lefts[i].size(); k++){
			len = lefts[i][k].first - i + 1;
			if (x >= len){
				sol = min(sol, cost[x-len]+lefts[i][k].second);
			}
		}
		for (int k = 0; k < rights[i].size(); k++){
			len = i - rights[i][k].first + 1;
			cost[len] = min(cost[len], rights[i][k].second);
		}
	}
	if (sol == INF) cout << "-1";
	else cout << sol;
	return 0;
}
