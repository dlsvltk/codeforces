//bfs - wanjontamseck
//O(n+m+k)
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
queue<pair<int, pair<int, int> > > q;
queue<pair<int, int> > wq;
char adjM[10001][10001];	//0: nothing, 1: lit+not visit, 2: lit+visit
//bool visit[10001][10001];
vector<int> adjR[10001];
vector<int> adjC[10001];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0 ,0 ,1, -1 };
bool rows[10002];
bool cols[10002];
int n, m;

bool wanjontamseck(int x, int y, int lev) {
	wq.push({ x,y });
	while (!wq.empty()) {
		int cx = wq.front().first;
		int cy = wq.front().second;		
		wq.pop();
		//check
		if (cx < 0 || cy <0 || cx >n || cy >m) continue;
		if (cx == n && cy == m) return 1;
		if (adjM[cx][cy] == 2) continue;
		adjM[cx][cy] = 2;
		q.push({ lev, { cx,cy } });
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(adjM[nx][ny] == 1)	wq.push({ nx,ny });
		}
	}
	return 0;
}
bool findL(int x, int y, int lev) {
	if (n - x < 2 || m - y < 2) return 1;
	for (int i = -2; i < 3; i++) {
		if (x + i < 1 || y + i<1 || x + i > n || y + i > m) continue;
		if (!rows[x + i]) {
			rows[x + i] = 1;
			for (int k = 0; k < adjR[x + i].size(); k++) {
				if (adjM[x + i][adjR[x + i][k]] == 1) {
					if (wanjontamseck(x + i, adjR[x+i][k], lev)) return 1;
				}
			}
		}
		if (!cols[y + i]) {
			cols[y + i] = 1;
			for (int k = 0; k < adjC[y + i].size(); k++) {
				if (adjM[adjC[y + i][k]][y+i] == 1) {
					if (wanjontamseck(adjC[y+i][k], y + i, lev)) return 1;
				}
			}
		}
	}
	return 0;
}
int bfs() {
	rows[0] = rows[n + 1] = 1;
	cols[0] = cols[m + 1] = 1;
	int lev;
	//auto push
	if (wanjontamseck(1, 1, 0)) return 0;
	
	while (!q.empty()) {
		lev = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		lev++;
		if (x == n || y == m)  return lev;
		if (findL(x, y, lev)) return lev;
	}
	return -1;
}
int main() {
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adjM[x][y] = 1;
		adjR[x].push_back(y);
		adjC[y].push_back(x);
	}
	printf("%d", bfs());
	return 0;
}
