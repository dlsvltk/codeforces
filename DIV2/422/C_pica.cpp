#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 2e9 + 1
using namespace std;

vector<pair<int, int> > pre[200001];
vector<pair<int, int> > after[200001];

int n, x;

ll bestCost[200001];

int main() {
	for (int i = 0; i < 200001; i++) bestCost[i] = INF;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int l, r, cost;
		cin >> l >> r >> cost;
		pre[r].push_back({ r - l + 1, cost });
		after[l].push_back({ r - l + 1, cost });
	}

	ll result = INF;

	for (int i = 1; i < 200001; i++) {//i - 1까지 bestCost가 갱신됨
		for (int j = 0; j < after[i].size(); j++) {//i를 기준으로 i - 1까지 갱신 되어있으므로 바로 답을 갱신한다.
			if (after[i][j].first < x) {
				result = min(result, after[i][j].second + bestCost[x - after[i][j].first]);
			}
		}
		for (int j = 0; j < pre[i].size(); j++) {//i까지 besCost를 갱신한다
			bestCost[pre[i][j].first] = min(bestCost[pre[i][j].first], (ll)pre[i][j].second);
		}
	}
	
	if (result == INF) {
		cout << -1;
	}
	else {
		cout << result;
	}
}