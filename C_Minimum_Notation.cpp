#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(v, it) \
for(vi::iterator it = (v).begin(); it != (v).end(); it++)
#define TRvii(v, it) \
for(vii::iterator it = (v).begin(); it != (v).end(); it++)
#define TRmsi(v, it) \
for(msi::iterator it = (v).begin(); it != (v).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p*p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}

int main(){
    int t;cin>>t;
    while(t--){
        // int n;cin>>n;
      string s;cin>>s;
      int n=s.size();
      int arr[s.size()];
      REP(i,0,s.size()-1){
        arr[i]=int(s[i]-'0');
      }
      vi ans(n+1,10);
      vi str;
      for(int i=n-1;i>=0;i--){
        if(arr[i]!=min(arr[i],ans[i+1])){
            str.push_back(min(arr[i]+1,9));
        }
        else{
            str.push_back(arr[i]);
        }
        ans[i]=(min(arr[i],ans[i+1]));
      }
      sort(str.begin(),str.end());
      for(auto it:str)cout<<it;
      cout<<endl;
}
}