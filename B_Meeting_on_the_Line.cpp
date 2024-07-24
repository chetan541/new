#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long double ll;
typedef vector<long double> vi;
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
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}


int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
      ll n;
  cin>>n;
  pair<ll,ll> pr[n];
  cout<<setprecision(10);
  for(ll i = 0;i<n;i++){
  	ll x;
  	cin>>x;
  	pr[i].F = x;
  }
  for(ll i = 0;i<n;i++){
  	ll x;
  	cin>>x;
  	pr[i].S = x;
  }
  sort(pr,pr+n);
  if(n == 1){
  	cout<<pr[0].F<<nl;
  	return;
  }
  long double hi = pr[n-1].F;
  long double lo = pr[0].F;
  long double m = (lo+hi)/2;
  while(hi - lo > 1e-9){
  	m  = (lo+hi)/2;
  	long double mh = (hi+m)/2;
  	long double ml = (lo+m)/2;
  	long double v1 = -1,v2 = -1;
  	for(ll i = 0;i<n;i++){
  		v1 = max(v1,pr[i].S + abs(ml - pr[i].F));
  		v2 = max(v2,pr[i].S + abs(mh - pr[i].F));
  	}
  	if(v1<v2){
  		hi = m;
  	}
  	else if(v2<v1){
  		lo = m;
  	}
  	else{
  		break;
  	}
 
  }
  cout<<m<<nl;
 
  
}  
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);clock_t t1=clock();
  int T;
  cin>>T;
  while(T--){
    solve();
  }
}

        
    }
}