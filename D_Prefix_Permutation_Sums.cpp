#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<ll, int> msi;
  
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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
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
        int n;cin>>n;
        vi v;
        REP(i,0,n-2){
            ll a;cin>>a;
            v.push_back(a);
        }
        ll prev=0;
        msi m;
        int flag1=0;
        REP(i,0,n-2){
            if(v[i]-prev>=2*n)flag1=1;
            m[v[i]-prev]++;
            prev=v[i];
        }
        ll sum=(1LL*n*(n+1)*1LL)/2;
        ll exp=0;
        for(auto it:m){
            exp+=it.first*it.second;
        }
        // if(flag1==1)cout<<"NO"<<endl;
        // else if(exp==sum)cout<<"YES"<<endl;
        // else if(sum-exp<=n && m[sum-exp]==0 && sum-exp>0 )cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
        if(sum<v[n-2]){
            cout<<"NO"<<endl;
        }
        else{
            ll a1=0,a2=0,doubt=0,cnt1=0,cnt2=0;
            REP(i,1,n){
                if(m[i]==0){
                    cnt1++;
                    if(a1==0)a1=i;
                    else a2=i;
                }
                
            }
            for(auto it:m){
                if(it.second>1 || it.first>n){
                    doubt=it.first;
                    cnt2++;
                }
            }
            if(cnt1==0)cout<<"NO"<<endl;
            else if(cnt1>2 || cnt2>1)cout<<"NO"<<endl;
            else if(a1+a2==doubt)cout<<"YES"<<endl;
            else if(a1+a2==sum-v[n-2])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}