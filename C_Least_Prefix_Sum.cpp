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
        int n,m;cin>>n>>m;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        ll cnt=0,front=0;
        priority_queue<int> q;
        // int tmp1=INT_MIN;
        q.push(INT_MIN);
        for(int i=m-1;i>=1;i--){
            // front+=v[i];
            front=front+v[i];
            if(v[i]>0)q.push(v[i]);
            if(front>0){front-=2*q.top();q.pop();cnt++;}
            // else {
            // front+=v[i];
            // // tmp1=max(tmp1,v[i]);
            // }

        }
        ll back=0;
        priority_queue<int> p;
        REP(i,m,n-1){
            back=back+v[i];
            if(v[i]<0)p.push(-1*v[i]);
            if(back<0 ){back+=2*p.top();p.pop();cnt++;}
            // else back+=v[i];
        }
        cout<<cnt<<endl;
        
    }
}