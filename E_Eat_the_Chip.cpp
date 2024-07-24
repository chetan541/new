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
bool check1(int a1,int a2,int b1,int b2){
    if(b1==a1+1 && b2==a2)return true;
    if(b1==a1+1 && b2==a2-1)return true;
    if(b1==a1+1 && b2==a2+1)return true;

    return false;
}
bool check2(int a1,int a2,int b1,int b2){
    if(b1==a1-11 && b2==a2)return true;
    if(b1==a1-1 && b2==a2-1)return true;
    if(b1==a1-1 && b2==a2+1)return true;

    return false;
}

int main(){
    int t;cin>>t;
    while(t--){
        int h,w,a1,a2,b1,b2;cin>>h>>w>>a1>>a2>>b1>>b2;
        if(b1>=a1){
            cout<<"Draw"<<endl;
        }
        

    }
}