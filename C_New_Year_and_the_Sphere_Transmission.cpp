#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int main() {
	ll N; cin >> N;
	vector<ll> ans;

	for (ll i = 1; i*i <= N; ++i) {
		if (N%i==0) {
			ans.push_back(N*(i-1)/2 + i);
			if (i*i!=N) {
				ans.push_back(N*(N/i-1)/2 + N/i);
			}
		}
	}
	sort(ans.begin(),ans.end());
	
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " \n"[i==ans.size()-1];
	}

}