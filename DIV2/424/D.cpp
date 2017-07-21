#include <iostream>#include <math.h>#include <algorithm>
using namespace std;
using namespace std;long long int in[100100], n;long long int key[100100], K;bool ok(long long int mx, long long int nt){ long long int k = 0; for (int j = 0; j < n; ++j) {  long long int i = in[j];  bool chk = false;  while (!chk && k < K)  {   int wnt = abs(i - key[k]) + abs(nt - key[k]); //거리를 절댓값으로 표현   if (wnt <= mx) chk = true;   k++;  }  if (!chk) return false; } return true;}
long long int p;int main(){
 cin >> n >> K >> p;
 for (int i = 0; i < n; ++i) cin >> in[i]; for (int i = 0; i < K; ++i) cin >> key[i]; sort(key, key + K); sort(in, in + n); //소트 한 뒤에 이분매칭 long long int low = 0, high = 3 * 1000000000; long long int res = high; while (low <= high) {  long long int mid = (low + high) / 2;  if (ok(mid, p))  {   res = mid;   high = mid - 1;  }  else  {   low = mid + 1;  } } cout << res;
}
