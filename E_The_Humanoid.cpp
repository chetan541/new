#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
        ll n,h;cin>>n>>h;
        vi v;
        int org=h;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int cnt1=0,cnt2=0,cnt3=0,g=2,b=1;
        ll pref=0;
        int arr1[]={2,2,3};
        int arr2[]={2,3,2};
        int arr3[]={3,2,2};
        int j=0;
        REP(i,0,n-1){
            // cout<<i<<" "<<h<<endl;
            if(h>v[i]){h+=v[i]/2;cnt1++;}
            else if(j<=2){
                h=h*arr1[j];i--;j++;
            }
            else{break;}
        }
        h=org;j=0;
         REP(i,0,n-1){
            // cout<<i<<" "<<h<<endl;
            if(h>v[i]){h+=v[i]/2;cnt2++;}
            else if(j<=2){
                h=h*arr2[j];i--;j++;
            }
            else{break;}
        }
        cnt2=max(cnt1,cnt2);
        h=org;j=0;
         REP(i,0,n-1){
            // cout<<i<<" "<<h<<endl;
            if(h>v[i]){h+=v[i]/2;cnt3++;}
            else if(j<=2){
                h=h*arr3[j];i--;j++;
            }
            else{break;}
        }
        cout<<max(cnt2,cnt3)<<endl;

        // cout<<cnt<<" "<<h<<endl;
    }
}