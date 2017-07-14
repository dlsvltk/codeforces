#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int k, n;

int arr[2001];
int sumArr[2001];

set<int> result;
vector<int> bList;

void solve(int pos, int bPos, int left) {
	if (left == 0) {
		result.insert(bList[bPos] - sumArr[pos]);
		return;
	}
	
	int dif = bList[bPos + 1] - bList[bPos];
	for (int i = pos + 1; i < k; i++) {
		if (sumArr[i] - sumArr[pos] == dif) {
			solve(i, bPos + 1, left - 1);
			break;
		}
	}
}

int main() {
	cin >> k >> n;
	cin >> arr[0];
	sumArr[0] = arr[0];
	for (int i = 1; i < k; i++) {
		cin >> arr[i];
		sumArr[i] = sumArr[i - 1] + arr[i];
	}
	sort(sumArr, sumArr + k);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		bList.push_back(input);
	}

	sort(bList.begin(), bList.end());
	for (int i = 0; i < k; i++) {
		solve(i, 0, n - 1);
	}
	cout << result.size() << endl;
}