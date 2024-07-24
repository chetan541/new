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
// vi SieveOfEratosthenes(int n) {
//     vi v;
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));

//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
//     for (int p = 2; p <= n; p++) {
//         if (prime[p])
//             v.push_back(p);
//     }
//     return v;
// }

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> v1,v2,v3;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(make_pair(a,i));
        }
        REP(i,0,n-1){
            int b;cin>>b;
            v2.push_back(make_pair(b,i));
        }
        REP(i,0,n-1){
            int c;cin>>c;
            v3.push_back(make_pair(c,i));
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        sort(v3.rbegin(),v3.rend());
        ll m=0;
        int f=0,s=0,c=0;
        REP(i,0,2){
            REP(j,0,2){
                REP(k,0,2){
                    if(v1[i].second!=v2[j].second && v2[j].second!=v3[k].second && v1[i].second!=v3[k].second ){
                        // m=max(m,v1[i].first +v2[j].first +v3[k].first);
                        if((v1[i].first +v2[j].first +v3[k].first)>m){
                            m=v1[i].first +v2[j].first +v3[k].first;
                            f=v1[i].first;s=v2[j].first;c=v3[k].first;
                        }
                    }
                }
            }
        }
        // cout<<m<<" "<<f<<" "<<s<<" "<<c<<endl;
        cout<<m<<endl;


        
    }
}