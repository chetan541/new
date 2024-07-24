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
        int n,k;cin>>n>>k;
        vi v;
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        vi ans;
        if(k==0)cout<<v[0]<<endl;
        if(k==1){
            ll temp=v[0];
            REP(i,0,n-1){
                REP(j,i+1,n-1){
                    temp=min(temp,abs(v[i]-v[j]));
                    ans.push_back(abs(v[i]-v[j]));
                }
            }
            cout<<temp<<endl;
        }
        if(k==2){
            ll temp=v[0];
            REP(i,0,n-1){
                REP(j,i+1,n-1){
                    temp=min(temp,abs(v[i]-v[j]));
                    ans.push_back(abs(v[i]-v[j]));
                }
            }
            // REP(i,0,n-1){
            //     ans.push_back(v[i]);
            // }
            sort(ans.begin(),ans.end());
            // for(auto it:ans)cout<<it<<" ";
            // cout<<endl;
            // temp=INT_MAX;
            REP(i,0,n-1){
                auto it1=lower_bound(ans.begin(),ans.end(),v[i]);
                // cout<<*(it1-1)<<" "<<endl;
                if(it1!=ans.end())temp=min(temp,abs(*it1-v[i]));
                else{
                    
                    temp=min(temp,abs(*(it1-1)-v[i]));
                }
                 it1=lower_bound(ans.begin(),ans.end(),v[i]);
                if(ans.begin()==it1)it1=it1+1;
                
                temp=min(temp,abs(*(it1-1)-v[i]));

                
            }
            cout<<temp<<endl;
        }
        if(k>=3)cout<<0<<endl;

        
    }
}