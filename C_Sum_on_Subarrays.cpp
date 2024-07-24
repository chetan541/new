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
        int n,k;cin>>n>>k;
        vi ans,pref;
        pref.push_back(0);
        int tmp=0;
        REP(i,1,30){
            if(i*(i+1)/2>=k){tmp=i;break;}
        }
        int num;
        if(tmp*(tmp+1)/2!=k){tmp--;
        int rem=k-tmp*(tmp+1)/2;
         num=(rem-tmp)*2-1;
         REP(i,1,n-tmp-1)cout<<-1000<<" ";
        cout<<num<<" ";
        REP(i,1,tmp)cout<<2<<" ";
        }
        else{
             REP(i,1,n-tmp)cout<<-1000<<" ";
             REP(i,1,tmp)cout<<1<<" ";
        }
        // cout<<tmp<<" "<<num<<" ";
        // REP(i,1,n-tmp-1)cout<<-1000<<" ";
        // cout<<num<<" ";
        // REP(i,1,tmp)cout<<1<<" ";
        cout<<endl;
    }
}